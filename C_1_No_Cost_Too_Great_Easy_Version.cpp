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
ai += 1 -> cost += 1

minimum cost such that there exist 2 integers ai, aj in array a such that:
gcd(ai, aj) > 1

if 2 even numbers are there then the cost is already 0

store the factors of all the ai in an hashmap

iterate through ai
find the factors of ai in square root n 

if mpp[factor] >= 2 -> cost will be 0

simultaneously find the factors of ai + 1 and check

if first case gives no answer and second gives then answer is 1 || if there is atleast 1 even number in the array else answer is 2

*/

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin>>b[i];

    int evenCnt = 0;
    for(auto i: a){
        if(i%2==0) evenCnt++;
    }
    if(evenCnt >=2){
        cout<<0<<endl;
        cout<<"D1"<<endl;
        return;
    }
    bool case3 = false;
    if(evenCnt == 1) case3 = true;

    unordered_map<int, int> mpp;
    for(auto N : a){
        if(N != 1) mpp[N]++;
        for(int i = 2; i*i <= N; i++){
            if(N%i == 0){
                mpp[i]++;
                if(N/i != i) mpp[N/i]++;
            }
        }
    }

    // for(auto i: mpp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    // bool case1 = false;
    bool case2 = false;
    // int it = 1;
    for(auto N : a){
        // cout<<"Iteration: "<<it<<endl;
        for(auto i: mpp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        if(mpp[N] >= 2){
            cout<<0<<endl;
            cout<<"D2"<<endl;
            return;
        }
        for(int i = 2; i*i<=N; i++){
            if(N%i == 0){
                if(mpp[i] >= 2){
                    cout<<0<<endl;
                    cout<<"D3"<<endl;
                    return;
                }
                if(N/i != i){
                    if(mpp[N/i] >= 2){
                        cout<<0<<endl;
                        cout<<"D4"<<endl;
                        return;
                    }
                }
            }
        }
        N++;
        if(N != 1) mpp[N]++;
        for(int i = 2; i*i <= N; i++){
            if(N%i == 0){
                mpp[i]++;
                if(N/i != i) mpp[N/i]++;
            }
        }
        // cout<<"check1"<<endl;
        // for(auto i: mpp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        if(mpp[N] >= 2){
            case2 = true;
            mpp[N]--;
            for(int i = 2; i*i <= N; i++){
                if(N%i == 0){
                    mpp[i]--;
                    if(N/i != i) mpp[N/i]--;
                }
            }
            continue;
        }
        for(int i = 2; i*i<=N; i++){
            if(N%i == 0){
                if(mpp[i] >= 2){
                    case2 = true;
                    break;
                }
                if(N/i != i){
                    if(mpp[N/i] >= 2){
                        case2 = true;
                        break;
                    }
                }
            }
        }
        mpp[N]--;
        for(int i = 2; i*i <= N; i++){
            if(N%i == 0){
                mpp[i]--;
                if(N/i != i) mpp[N/i]--;
            }
        }
        // cout<<"check2"<<endl;
        // for(auto i: mpp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        // it++;
    }

    if(case2 || case3){
        cout<<1<<endl;
        return;
    }

    cout<<2<<endl;

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
