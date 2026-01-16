#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
#include <numeric>
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************

*/

class DisjointSet{
    vector<int> rank, parent, size;

public: 
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ultimateParentOfU = findUltimateParent(u);
        int ultimateParentOfV = findUltimateParent(v);
        if(ultimateParentOfU == ultimateParentOfV) return; 
        if(rank[ultimateParentOfU] < rank[ultimateParentOfV]){
            parent[ultimateParentOfU] = ultimateParentOfV;
        }
        else if(rank[ultimateParentOfV] < rank[ultimateParentOfU]){
            parent[ultimateParentOfV] = ultimateParentOfU;
        }
        else{
            parent[ultimateParentOfV] = ultimateParentOfU; 
            rank[ultimateParentOfU]++; 
        }
    }

    void unionBySize(int u, int v){
            int ultimateParentOfU = findUltimateParent(u);
            int ultimateParentOfV = findUltimateParent(v);
            if(ultimateParentOfU == ultimateParentOfV) return; 
            if(size[ultimateParentOfU] < size[ultimateParentOfV]){
                parent[ultimateParentOfU] = ultimateParentOfV;
                size[ultimateParentOfV] += size[ultimateParentOfU];
            }
            else{ 
                parent[ultimateParentOfV] = ultimateParentOfU;
                size[ultimateParentOfU] += size[ultimateParentOfV];
            }
        }
};

bool cmp(const vector<int> &a, const vector<int> &b){
    if (a[0] != b[0]) return a[0] > b[0]; 
    return a[1] < b[1];    
}

void solve(){
    int n; cin>>n;
    vector<vector<int>> pairs(n, vector<int>(4, 0));
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        pairs[i][0] = b-a;
        pairs[i][1] = a;
        pairs[i][2] = b;
        pairs[i][3] = i;
    }

    vector<int> ans;

    DisjointSet ds(2*n);

    sort(pairs.begin(), pairs.end(), cmp);
    for(auto pair : pairs){
        int u = pair[1];
        int v = pair[2];
        if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
            ds.unionBySize(u, v);
            ans.push_back(pair[3]+1);
        }
    }

    cout<<ans.size()<<endl;
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
