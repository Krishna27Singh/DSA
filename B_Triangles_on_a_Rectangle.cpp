#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <string>
using namespace std;

long long calculateArea( int x1, int y1, int x2, int y2, int x3, int y3) {
    long long area = abs((x1*1LL*(y2 - y3) + x2*1LL*(y3 - y1) + x3*1LL*(y1 - y2)));
    return area;
}

void solve(){
    int w, h; cin>>w>>h;
    int k1; cin>>k1;
    vector<int> bottomEdge(k1);
    for(int i = 0; i<k1; i++) cin>>bottomEdge[i];
    int k2; cin>>k2;
    vector<int> topEdge(k2);
    for(int i = 0; i<k2; i++) cin>>topEdge[i];  
    int k3; cin>>k3;
    vector<int> leftEdge(k3);
    for(int i = 0; i<k3; i++) cin>>leftEdge[i];  
    int k4; cin>>k4;
    vector<int> rightEdge(k4);
    for(int i = 0; i<k4; i++) cin>>rightEdge[i];

    long long maxArea = 0;

    int x1, y1, x2, y2, x3, y3;
    x1 = bottomEdge[0]; y1 = 0;
    x2 = bottomEdge[k1-1]; y2 = 0;
    for(int i = 0; i<k2; i++){
        x3 = topEdge[i]; y3 = h;
        long long area = calculateArea(x1, y1, x2, y2, x3, y3);
        maxArea = max(maxArea, area);
    }

    x1 = topEdge[0]; y1 = h;
    x2 = topEdge[k2-1]; y2 = h;
    for(int i = 0; i<k1; i++){
        x3 = bottomEdge[i]; y3 = 0;
        long long area = calculateArea(x1, y1, x2, y2, x3, y3);
        maxArea = max(maxArea, area);
    }

    x1 = 0; y1 = leftEdge[0];
    x2 = 0; y2 = leftEdge[k3-1];
    for(int i = 0; i<k4; i++){
        x3 = w; y3 = rightEdge[i];
        long long area = calculateArea(x1, y1, x2, y2, x3, y3);
        maxArea = max(maxArea, area);
    }

    x1 = w; y1 = rightEdge[0];
    x2 = w; y2 = rightEdge[k4-1];
    for(int i = 0; i<k3; i++){
        x3 = 0; y3 = leftEdge[i];
        long long area = calculateArea(x1, y1, x2, y2, x3, y3);
        maxArea = max(maxArea, area);   
    }

    cout<<maxArea<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
