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

int globalCnt[1000005];

void solve() {
    int n; cin>>n;
    vector<vector<int>> a(n);
    long long totalLen = 0;
    
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        a[i].resize(l);
        for (int j = 0; j < l; ++j) {
            cin >> a[i][j];
            globalCnt[a[i][j]]++;
        }
        totalLen += l;
    }

    long long currentSM = 0;
    vector<int> M(n);       
    vector<int> nextM(n);  
    long long sourceDF = 0;

    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
        
        int m1 = -1, m2 = -1; 
        int curr = 0;         
        int idx = 0;
        int sz = a[i].size();
        
        while (m2 == -1) {
            if (idx < sz && a[i][idx] == curr) {
                while (idx < sz && a[i][idx] == curr) idx++;
                curr++;
            } else {
                if (m1 == -1) m1 = curr;
                else m2 = curr;
                curr++;
            }
        }
        M[i] = m1;
        nextM[i] = m2;
        currentSM += m1;
        
        int p = 0;
        while(p < sz) {
            int val = a[i][p];
            int start = p;
            while(p < sz && a[i][p] == val) p++;
            int count = p - start;
            
            if (val > M[i]) break; 

            if (val < M[i] && count == 1) {
                sourceDF += (long long)(val - M[i]) * (n - 1);
            }
        }
    }

    long long ops = totalLen * (n - 1);
    long long val = currentSM * ops;
    
    long long DDS = 0;
    for (int k = 0; k < n; ++k) {
        int target = M[k];
        int count = globalCnt[target];
        
        if (count > 0) {
            long long diff = nextM[k] - M[k];
            DDS += (long long)count * diff;
        }
    }

    cout << val + sourceDF + DDS <<endl;

    for (int i = 0; i < n; ++i) {
        for (int x : a[i]) {
            globalCnt[x]--;
        }
    }
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
