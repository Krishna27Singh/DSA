#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <json/json.h>

using namespace std;

struct Point { double x, y; };

struct NFZ {
    string shape;
    double cx, cy, r;
    double xmin, ymin, xmax, ymax;
    double tStart, tEnd;
    double bXmin, bYmin, bXmax, bYmax;
};

struct Delivery {
    string id;
    double x, y;
    double weight;
    double deadline;
    double angle;
    bool delivered;
    bool failed;
};

struct Station {
    double x, y;
    int slots;
    double distW;
};

struct Drone {
    string id;
    double maxPayload;
    double currentT;
    int originalIndex;
};

struct Action {
    double x, y, t;
    string type;
    vector<string> dIds;
    string dId;
};

struct RouteResult {
    bool valid = false;
    double finalT = 0.0;
    double totalEnergy = 0.0;
    double scoreCost = 1e9;
    vector<Action> actions;
};

struct PathResult {
    bool valid = false;
    double finalT = 0.0;
    double totalDist = 0.0;
    vector<Action> pathActions; 
};

bool intersectsRect(double ax, double ay, double bx, double by, double xmin, double ymin, double xmax, double ymax, double &tEntry, double &tExit) {
    double vx = bx - ax, vy = by - ay;
    double len = hypot(vx, vy);
    double uEnter = 0.0, uExit = 1.0;
    double p[4] = {-vx, vx, -vy, vy};
    double q[4] = {ax - xmin, xmax - ax, ay - ymin, ymax - ay};

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) return false;
        } else {
            double r = q[i] / p[i];
            if (p[i] < 0) {
                if (r > uExit) return false;
                if (r > uEnter) uEnter = r;
            } else {
                if (r < uEnter) return false;
                if (r < uExit) uExit = r;
            }
        }
    }
    if (uEnter <= uExit) {
        tEntry = uEnter * len; tExit = uExit * len;
        return true;
    }
    return false;
}

bool intersectsCircle(double ax, double ay, double bx, double by, double cx, double cy, double rad, double &tEntry, double &tExit) {
    double vx = bx - ax, vy = by - ay;
    double len = hypot(vx, vy);
    if (len == 0) {
        if (hypot(ax - cx, ay - cy) <= rad) { tEntry = 0; tExit = 0; return true; }
        return false;
    }
    double dx = vx / len, dy = vy / len;
    double fx = ax - cx, fy = ay - cy;
    double b = 2 * (fx * dx + fy * dy);
    double c = (fx * fx + fy * fy) - rad * rad;
    double delta = b * b - 4 * c;
    if (delta < 0) return false;
    
    double sqrtDelta = sqrt(delta);
    double u1 = (-b - sqrtDelta) / 2.0;
    double u2 = (-b + sqrtDelta) / 2.0;
    double uEnter = max(0.0, min(u1, u2));
    double uExit = min(len, max(u1, u2));
    
    if (uEnter <= uExit && uExit >= 0 && uEnter <= len) {
        tEntry = uEnter; tExit = uExit; return true;
    }
    return false;
}

double getSafeDeparture(double startT, double ax, double ay, double bx, double by, const vector<NFZ>& nfzs) {
    double t = startT;
    double len = hypot(bx - ax, by - ay);
    if (len == 0) return t;
    
    double minX = min(ax, bx), maxX = max(ax, bx);
    double minY = min(ay, by), maxY = max(ay, by);
    bool collision = true;
    int safetyBreaker = 0;
    
    while (collision && safetyBreaker++ < 50) {
        collision = false;
        for (const auto& nfz : nfzs) {
            if (maxX < nfz.bXmin || minX > nfz.bXmax || maxY < nfz.bYmin || minY > nfz.bYmax) continue; 
            
            double tEntry, tExit;
            bool hit = nfz.shape == "circle" ? 
                intersectsCircle(ax, ay, bx, by, nfz.cx, nfz.cy, nfz.r, tEntry, tExit) : 
                intersectsRect(ax, ay, bx, by, nfz.xmin, nfz.ymin, nfz.xmax, nfz.ymax, tEntry, tExit);
            
            if (hit) {
                double absTEntry = t + tEntry;
                double absTExit = t + tExit;
                if (absTEntry < nfz.tEnd && absTExit > nfz.tStart) {
                    double waitNeeded = nfz.tEnd - tEntry;
                    if (waitNeeded > t) {
                        t = waitNeeded + 1e-4; 
                        collision = true;
                        break;
                    }
                }
            }
        }
    }
    return t;
}

PathResult getFastPath(double ax, double ay, double bx, double by, double startT, const vector<NFZ>& nfzs) {
    PathResult res;
    double tDep = getSafeDeparture(startT, ax, ay, bx, by, nfzs);
    double dist = hypot(bx - ax, by - ay);
    
    res.valid = true;
    res.finalT = tDep + dist;
    res.totalDist = dist;
    if (tDep > startT) res.pathActions.push_back({ax, ay, tDep, "WAIT", {}, ""});

    if (tDep - startT < 2.0) return res;

    PathResult best = res; 
    for (const auto& nfz : nfzs) {
        double minX = min(ax, bx), maxX = max(ax, bx);
        double minY = min(ay, by), maxY = max(ay, by);
        if (maxX < nfz.bXmin || minX > nfz.bXmax || maxY < nfz.bYmin || minY > nfz.bYmax) continue;
        
        double tEntry, tExit;
        bool hit = false;
        if (nfz.shape == "circle") hit = intersectsCircle(ax, ay, bx, by, nfz.cx, nfz.cy, nfz.r, tEntry, tExit);
        else hit = intersectsRect(ax, ay, bx, by, nfz.xmin, nfz.ymin, nfz.xmax, nfz.ymax, tEntry, tExit);

        if (hit) {
            double eps = 0.5; 
            Point wps[4] = {
                {nfz.bXmin - eps, nfz.bYmin - eps},
                {nfz.bXmax + eps, nfz.bYmin - eps},
                {nfz.bXmin - eps, nfz.bYmax + eps},
                {nfz.bXmax + eps, nfz.bYmax + eps}
            };

            for (int i=0; i<4; i++) {
                double t1 = getSafeDeparture(startT, ax, ay, wps[i].x, wps[i].y, nfzs);
                double d1 = hypot(wps[i].x - ax, wps[i].y - ay);
                double arr1 = t1 + d1;

                double t2 = getSafeDeparture(arr1, wps[i].x, wps[i].y, bx, by, nfzs);
                double d2 = hypot(bx - wps[i].x, by - wps[i].y);
                double arr2 = t2 + d2;

                if (arr2 < best.finalT) {
                    best.finalT = arr2;
                    best.totalDist = d1 + d2;
                    best.pathActions.clear();
                    if (t1 > startT) best.pathActions.push_back({ax, ay, t1, "WAIT", {}, ""});
                    best.pathActions.push_back({wps[i].x, wps[i].y, arr1, "WAYPOINT", {}, ""});
                    if (t2 > arr1) best.pathActions.push_back({wps[i].x, wps[i].y, t2, "WAIT", {}, ""});
                }
            }
        }
    }
    return best;
}

void addAction(vector<Action>& acts, double x, double y, double t, string type, string dId = "", vector<string> dIds = {}) {
    acts.push_back({x, y, t, type, dIds, dId});
}

RouteResult evaluatePermutation(const Drone& dr, const vector<Delivery*>& seq, const vector<NFZ>& nfzs, const vector<Station>& stations, double wx, double wy) {
    RouteResult res;
    double currentT = dr.currentT;
    double currentE = 500.0;
    double payload = 0.0;
    vector<string> pickupIds;
    
    for (auto d : seq) {
        payload += d->weight;
        pickupIds.push_back(d->id);
    }
    
    if (payload > dr.maxPayload + 1e-9) return res;

    double currX = wx, currY = wy;
    vector<Action> acts;
    
    PathResult toFirst = getFastPath(currX, currY, seq[0]->x, seq[0]->y, currentT, nfzs);
    if (!toFirst.valid) return res;
    
    double initialWait = toFirst.pathActions.empty() ? 0 : (toFirst.pathActions[0].type == "WAIT" ? toFirst.pathActions[0].t - currentT : 0);
    if (initialWait > 0) addAction(acts, currX, currY, currentT + initialWait, "WAIT");
    
    currentT += initialWait;
    addAction(acts, currX, currY, currentT, "PICKUP", "", pickupIds);

    for (size_t i = 0; i < seq.size(); i++) {
        auto d = seq[i];
        PathResult path = getFastPath(currX, currY, d->x, d->y, currentT, nfzs);
        if (!path.valid) return res;
        
        double eUsed = path.totalDist * (1.0 + payload);
        
        if (currentE < eUsed) {
            bool charged = false;
            for (const auto& s : stations) {
                PathResult toStation = getFastPath(currX, currY, s.x, s.y, currentT, nfzs);
                if (!toStation.valid) continue;
                
                double eToStation = toStation.totalDist * (1.0 + payload);
                if (currentE >= eToStation) {
                    for(auto& a : toStation.pathActions) acts.push_back(a);
                    currentT = toStation.finalT;
                    currentE -= eToStation;
                    
                    double chargeAmt = 500.0 - currentE;
                    double chargeTime = chargeAmt / 2.0;
                    
                    addAction(acts, s.x, s.y, currentT, "CHARGE");
                    currentT += chargeTime;
                    currentE += chargeAmt;
                    addAction(acts, s.x, s.y, currentT, "CHARGE_COMPLETE");
                    
                    path = getFastPath(s.x, s.y, d->x, d->y, currentT, nfzs);
                    eUsed = path.totalDist * (1.0 + payload);
                    charged = true;
                    currX = s.x; currY = s.y;
                    break;
                }
            }
            if (!charged) return res;
        }

        for (auto& a : path.pathActions) acts.push_back(a);
        
        currentT = path.finalT;
        if (currentT > d->deadline) return res;
        
        currentE -= eUsed;
        currX = d->x;
        currY = d->y;
        payload -= d->weight;
        
        addAction(acts, currX, currY, currentT, "DELIVER", d->id);
    }

    PathResult returnPath = getFastPath(currX, currY, wx, wy, currentT, nfzs);
    if (!returnPath.valid) return res;
    double eHome = returnPath.totalDist * 1.0;

    if (currentE >= eHome) {
        for (auto& a : returnPath.pathActions) acts.push_back(a);
        currentT = returnPath.finalT;
        currentE -= eHome;
        addAction(acts, wx, wy, currentT, "RETURN");
    } else {
        bool foundStation = false;
        double bestReturnT = 1e18;
        vector<Action> bestStationActs;
        double bestEnergyLeft = 0;

        for (const auto& s : stations) {
            PathResult toStation = getFastPath(currX, currY, s.x, s.y, currentT, nfzs);
            if (!toStation.valid) continue;
            
            double es = toStation.totalDist * 1.0;
            if (currentE < es) continue;
            
            double eAts = currentE - es;
            PathResult stToHome = getFastPath(s.x, s.y, wx, wy, toStation.finalT, nfzs);
            if (!stToHome.valid) continue;
            
            double eReqHome = stToHome.totalDist * 1.0;
            if (eReqHome > 500.0) continue;
            
            double chargeAmt = max(0.0, eReqHome - eAts);
            double tReady = toStation.finalT + (chargeAmt / 2.0);
            
            stToHome = getFastPath(s.x, s.y, wx, wy, tReady, nfzs);
            
            if (stToHome.finalT < bestReturnT) {
                bestReturnT = stToHome.finalT;
                foundStation = true;
                bestEnergyLeft = 500.0 - eReqHome;
                
                bestStationActs.clear();
                for(auto& a: toStation.pathActions) bestStationActs.push_back(a);
                bestStationActs.push_back({s.x, s.y, toStation.finalT, "CHARGE", {}, ""});
                bestStationActs.push_back({s.x, s.y, tReady, "CHARGE_COMPLETE", {}, ""});
                for(auto& a: stToHome.pathActions) bestStationActs.push_back(a);
                bestStationActs.push_back({wx, wy, stToHome.finalT, "RETURN", {}, ""});
            }
        }
        
        if (!foundStation) return res;
        for (auto& a : bestStationActs) acts.push_back(a);
        currentT = bestReturnT;
        currentE = bestEnergyLeft;
    }

    res.valid = true;
    res.finalT = currentT;
    res.totalEnergy = 500.0 - currentE;
    res.scoreCost = (res.totalEnergy * 0.1) + ((currentT - dr.currentT) * 0.05);
    res.actions = acts;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string inputStr((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
    Json::Value inputData;
    Json::CharReaderBuilder rb;
    string errs;
    istringstream ss(inputStr);
    Json::parseFromStream(rb, ss, &inputData, &errs);
    
    double mapW = inputData["map_size"][0].asDouble();
    double mapH = inputData["map_size"][1].asDouble();
    double wx = mapW / 2.0, wy = mapH / 2.0;
    
    vector<Drone> drones;
    vector<string> originalDroneIds(inputData["drones"].size());
    int idx = 0;
    for (const auto& d : inputData["drones"]) {
        Drone dr;
        dr.id = d["id"].asString();
        dr.maxPayload = d["max_payload"].asDouble();
        dr.currentT = 0.0;
        dr.originalIndex = idx;
        originalDroneIds[idx] = dr.id;
        drones.push_back(dr);
        idx++;
    }
    
    vector<Delivery> deliveries;
    for (const auto& d : inputData["deliveries"]) {
        Delivery del;
        del.id = d["id"].asString();
        del.x = d["x"].asDouble(); del.y = d["y"].asDouble();
        del.weight = d["weight"].asDouble();
        del.deadline = d["deadline"].asDouble();
        del.angle = atan2(del.y - wy, del.x - wx); 
        del.delivered = false; del.failed = false;
        deliveries.push_back(del);
    }
    
    sort(deliveries.begin(), deliveries.end(), [](const Delivery& a, const Delivery& b) {
        return a.angle < b.angle;
    });
    
    vector<NFZ> nfzs;
    if (inputData.isMember("no_fly_zones")) {
        double eps = 0.01; 
        for (const auto& n : inputData["no_fly_zones"]) {
            NFZ nfz;
            nfz.shape = n["shape"].asString();
            if (nfz.shape == "circle") {
                nfz.cx = n["center"][0].asDouble(); nfz.cy = n["center"][1].asDouble();
                nfz.r = n["radius"].asDouble();
                nfz.bXmin = nfz.cx - nfz.r - eps; nfz.bXmax = nfz.cx + nfz.r + eps;
                nfz.bYmin = nfz.cy - nfz.r - eps; nfz.bYmax = nfz.cy + nfz.r + eps;
            } else {
                nfz.xmin = n["corners"][0][0].asDouble(); nfz.ymin = n["corners"][0][1].asDouble();
                nfz.xmax = n["corners"][1][0].asDouble(); nfz.ymax = n["corners"][1][1].asDouble();
                if (nfz.xmin > nfz.xmax) swap(nfz.xmin, nfz.xmax);
                if (nfz.ymin > nfz.ymax) swap(nfz.ymin, nfz.ymax);
                nfz.bXmin = nfz.xmin - eps; nfz.bXmax = nfz.xmax + eps;
                nfz.bYmin = nfz.ymin - eps; nfz.bYmax = nfz.ymax + eps;
            }
            nfz.tStart = n["T_start"].asDouble(); nfz.tEnd = n["T_end"].asDouble();
            nfzs.push_back(nfz);
        }
    }
    
    vector<Station> stations;
    if (inputData.isMember("charging_stations")) {
        for (const auto& s : inputData["charging_stations"]) {
            Station st;
            st.x = s["x"].asDouble(); st.y = s["y"].asDouble();
            st.slots = s["slots"].asInt();
            stations.push_back(st);
        }
    }
    
    vector<Json::Value> dronePaths(drones.size(), Json::arrayValue);
    int remaining = deliveries.size();
    
    while (remaining > 0) {
        sort(drones.begin(), drones.end(), [](const Drone& a, const Drone& b) {
            return a.currentT < b.currentT;
        });
        
        Drone& dr = drones[0];
        vector<Delivery*> batch;
        double currentWeight = 0.0;
        
        Delivery* primary = nullptr;
        for (auto& d : deliveries) {
            if (!d.delivered && !d.failed && currentWeight + d.weight <= dr.maxPayload + 1e-9) {
                primary = &d;
                break;
            }
        }
        
        if (!primary) {
            dr.currentT += 100.0; 
            continue; 
        }
        
        batch.push_back(primary);
        currentWeight += primary->weight;
        
        for (auto& d : deliveries) {
            if (!d.delivered && !d.failed && &d != primary) {
                if (batch.size() < 4 && currentWeight + d.weight <= dr.maxPayload + 1e-9) {
                    batch.push_back(&d);
                    currentWeight += d.weight;
                }
            }
        }
        
        bool routeCommitted = false;
        vector<Delivery*> originalBatch = batch;
        
        while (!batch.empty()) {
            sort(batch.begin(), batch.end(), [](Delivery* a, Delivery* b) { return a->id < b->id; });
            RouteResult bestRoute;
            
            do {
                RouteResult r = evaluatePermutation(dr, batch, nfzs, stations, wx, wy);
                if (r.valid && r.scoreCost < bestRoute.scoreCost) {
                    bestRoute = r;
                }
            } while (next_permutation(batch.begin(), batch.end(), [](Delivery* a, Delivery* b) { return a->id < b->id; }));
            
            if (bestRoute.valid) {
                auto& pArray = dronePaths[dr.originalIndex];
                for (const auto& a : bestRoute.actions) {
                    Json::Value act;
                    act["x"] = a.x; act["y"] = a.y; act["t"] = a.t;
                    act["action"] = a.type;
                    if (a.type == "PICKUP") {
                        Json::Value ids(Json::arrayValue);
                        for (const auto& id : a.dIds) ids.append(id);
                        act["delivery_ids"] = ids;
                    }
                    if (a.type == "DELIVER") act["delivery_id"] = a.dId;
                    pArray.append(act);
                }
                
                dr.currentT = bestRoute.finalT;
                for (auto d : batch) d->delivered = true;
                remaining -= batch.size();
                routeCommitted = true;
                break;
            } else {
                originalBatch.pop_back();
                batch = originalBatch;
            }
        }
        
        if (!routeCommitted) {
            primary->failed = true;
            remaining--;
        }
    }
    
    Json::Value flightManifest(Json::arrayValue);
    for (size_t i = 0; i < dronePaths.size(); i++) {
        if (!dronePaths[i].empty()) {
            Json::Value droneManifest;
            droneManifest["drone_id"] = originalDroneIds[i];
            droneManifest["path"] = dronePaths[i];
            flightManifest.append(droneManifest);
        }
    }
    
    Json::Value output;
    output["flight_manifest"] = flightManifest;
    Json::StreamWriterBuilder wb;
    wb["indentation"] = "  ";
    cout << Json::writeString(wb, output) << endl;
    
    return 0;
}