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
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
#define mp make_pair
#define all(x) (x).begin(),(x).end()

void solve(){
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i<n-1; i++){
        int u, v; cin>>u>>v;
        int x, y; cin>>x>>y;
        if(x>y){
            adj[v].push_back(u);
        }
        else{
            adj[u].push_back(v);
        }
    }
    vector<int> p(n, -1);

    vector<int> inDegree(n+1, 0);
    for(int i = 1; i<=n; i++){
        for(auto it: adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 1; i<=n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    int valueToAssign = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        p[node-1] = valueToAssign;
        valueToAssign++;
        for(auto it: adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }

    for(auto i: p){
        cout<<i<<" ";
    }
    cout<<endl;

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
