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

void solve(){
    int n; cin>>n;

    unordered_map<int, vector<int>> mpp;
    // longest -> node
    int temp = n;
    int longest = 0;
    int node = 1;
    while(temp--){
        cout<<"?"<<" ";
        cout<<node<<" ";
        cout<<n<<" ";
        for(int i = 1; i<=n; i++) cout<<i<<" ";
        cout<<endl;
        int output; cin>>output;
        cout.flush();

        longest = max(longest, output);
        mpp[output].push_back(node);

        node++;
    }

    vector<int> path;
    path.push_back(mpp[longest][0]);
    int curNode = mpp[longest][0];

    while(longest > 1){
        auto neighbours = mpp[longest-1];
        for(auto neighbour : neighbours){
            cout<<"?"<<" ";
            cout<<curNode<<" ";
            cout<<2<<" ";
            cout<<curNode<<" "<<neighbour<<" ";
            cout<<endl;
            int output; cin>>output;
            cout.flush();
            if(output == 2){
                path.push_back(neighbour);
                curNode = neighbour;
                longest--;
                break;
            }
        }
    }

    cout<<"!"<<" ";
    cout<<path.size()<<" ";
    for(auto i: path) cout<<i<<" ";
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
