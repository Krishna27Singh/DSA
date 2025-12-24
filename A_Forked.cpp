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
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    // int a, b; cin>>a>>b;
    // int xk, yk; cin>>xk>>yk;
    // int xq, yq; cin>>xq>>yq;
    int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};
        int a, b; cin >> a >> b;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        set<pair<int, int>> st1, st2;
        for(int j = 0; j < 4; j++){
            st1.insert({x1+dx[j]*a, y1+dy[j]*b});
            st2.insert({x2+dx[j]*a, y2+dy[j]*b});
            st1.insert({x1+dx[j]*b, y1+dy[j]*a});
            st2.insert({x2+dx[j]*b, y2+dy[j]*a});
        }
        int ans = 0;
        for(auto x : st1)
            if(st2.find(x) != st2.end())
                ans++;
        cout << ans <<endl;

    // if(xk == xq || yk == yq){
    //     int cnt = 0;
    //     if(yk == yq){
    //         if(xk<xq){
    //             if(xk+a == xq-a && yk+b==yq+b) cnt++;
    //             if(xk+a == xq-b && yk+b==yk+a) cnt++;
    //             if(xk+b == xq-a && yk+a==yq+b) cnt++;
    //             if(xk+b == xq-b && yk+a==yq+a) cnt++;
    //             if(a==b) cnt-=3;
    //         }
    //         else{

    //         }
    //     }
    // }

    // int cnt = 0;
    // //case1
    // if(yk>yq && xk<xq){
    //     if(xk+a == xq-b && yk-b == yq+a) cnt++;
    //     if(xk+a == xq-a && yk-b == yq+b) cnt++;
    //     if(xk+b == xq-b && yk-a == yq+a) cnt++;
    //     if(xk+b == xq-a && yk-a == yq+b) cnt++;
    //     if(a==b) cnt-=3;
    // }

    // //case2
    // else if(yk>yq && xk>xq){
    //     if(xk-a == xq+b && yk-b == yq+a) cnt++;
    //     if(xk-a == xq+a && yk-b == yq+b) cnt++;
    //     if(xk-b == xq+b && yk-a == yq+a) cnt++;
    //     if(xk-b == xq+a && yk-a == yq+b) cnt++;
    //     if(a==b) cnt-=3;
    // }

    // //case3 
    // else if(yk<yq && xk<xq){
    //     if(xk+a == xq-b && yk+b == yq-a) cnt++;
    //     if(xk+a == xq-a && yk+b == yq-a) cnt++;
    //     if(xk+b == xq-b && yk+a == yq-a) cnt++;
    //     if(xk+b == xq-a && yk+a == yq-b) cnt++;
    //     if(a==b) cnt-=3;
    // }

    // else if(yk<yq && xk>xq){
    //     if(xk-a == xq+b && yk+b == yq-a) cnt++;
    //     if(xk-a == xq+a && yk+b == yq-b) cnt++;
    //     if(xk-b == xq+b && yk+a == yq-b) cnt++;
    //     if(xk-b == xq+a && yk+a == yq-b) cnt++;
    //     if(a==b) cnt-=3;
    // }

    // cout<<cnt<<endl;

    // Output
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
