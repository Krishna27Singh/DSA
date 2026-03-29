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
using namespace std;

#define ll long long


long MaxScore(int N, int D, int K, int P, vector<vector<int>> Films) {
    vector<vector<int>> G(K + 1);
    
    for (int idx = 0; idx < N; ++idx) {
        int id = Films[idx][0];
        int val = Films[idx][1];
        G[id].push_back(val);
    }
    
    for (int i = 1; i <= K; ++i) {
        sort(G[i].begin(), G[i].end(), greater<int>());
    }
    
    priority_queue<int, vector<int>, greater<int>> topi;
    ll si = 0;
    ll perfect = -2e18; 
    int ss = 0;
    
    for (int l = 1; l <= D; ++l) {
        
        for (int i = 1; i <= K; ++i) {
            if (G[i].size() >= l) {
                int curi = G[i][l - 1];
                
                ss++;
                if (topi.size() < D) {
                    topi.push(curi);
                    si += curi;
                } else if (!topi.empty() && curi > topi.top()) {
                    si -= topi.top();
                    topi.pop();
                    
                    topi.push(curi);
                    si += curi;
                }
            }
        }
        
        if (ss >= D) {
            long long a = max(0LL, 2LL * l - D - 1LL);
            long long b = a * P;
            
            long long sc = si - b;
            
            if (sc > perfect) {
                perfect = sc;
            }
        }
    }
    
    return perfect;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, d, k, p;
    if (cin >> n >> d >> k >> p) {
        vector<vector<int>> films_arr(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> films_arr[i][0] >> films_arr[i][1];
        }
        
        cout << MaxScore(n, d, k, p, films_arr) << "\n";
    }
    
    return 0;
}