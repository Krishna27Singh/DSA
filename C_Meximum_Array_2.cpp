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
    int n, k, q; cin>>n>>k>>q;
    vector<int> c(q);
    vector<int> l(q);
    vector<int> r(q);
    for(int i = 0; i<q; i++){
        cin>>c[i];
        cin>>l[i];
        cin>>r[i];
        l[i]--; r[i]--;
    }

    vector<int> a(n, 1e9);

    //query 1
    for(int i = 0; i<q; i++){
        if(c[i]==1){
            for(int j = l[i]; j<=r[i]; j++) a[j]=k;
        }
    }
    //query 2
    for(int i = 0; i<q; i++){
        if(c[i]==2){
            vector<bool> have(k, false);
            for (int j = l[i]; j <= r[i]; j++) {
            if (0 <= a[j] && a[j] < k)
                have[a[j]] = true;
            }
            vector<int> missing;
            for (int v = 0; v < k; v++)
            if (!have[v]) missing.push_back(v);

            int ptr = 0;
            for(int j = l[i]; j<=r[i]; j++){
                if(a[j]==k){
                    a[j] = 1e9;
                    continue;
                }
                if(a[j]<k) continue;
                if(ptr<missing.size()) a[j] = missing[ptr++];
                else break;
            }
        }
    }

    for(auto i: a) cout<<i<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
