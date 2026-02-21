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
x -> element from own array whose current turn is
y -> maximum element from the opponents array 

if x >= y -> delete from opponents array
else y = y - x 

who wins?


*/

void solve(){
    int n, m; cin >> n >> m;
    
    // Max-heaps to automatically keep the largest elements at the top
    priority_queue<int> a;
    priority_queue<int> b;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push(x);
    }
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        b.push(x);
    }

    bool aliceTurn = true;
    
    // Play the game until one array is empty
    while(!a.empty() && !b.empty()){
        if(aliceTurn){
            aliceTurn = false;
            int x = a.top(); // Alice's chosen element
            int y = b.top(); // Bob's maximal element
            
            b.pop(); // Temporarily remove Bob's maximal element
            
            if(x < y){
                // If y > x, y is decreased by x. Put the remaining value back.
                b.push(y - x);
            }
            // If x >= y, it is destroyed (we just don't push it back)
        }
        else {
            aliceTurn = true;
            int x = b.top(); // Bob's chosen element
            int y = a.top(); // Alice's maximal element
            
            a.pop(); // Temporarily remove Alice's maximal element
            
            if(x < y){
                a.push(y - x);
            }
        }
    }

    // Output the winner
    if(!a.empty()){
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
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
