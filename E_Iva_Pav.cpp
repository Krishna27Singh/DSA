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
l <= r
f(l, r) = al & al+1 & al+2 ... & ar

l, k
largest r such that f(l, r) >= k
*/

/*
****************************************** Testing ****************************************************

*/

class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(vector<int> &a) {
        n = a.size();
        tree.resize(4*n);
        build(1, 0, n-1, a);
    }

    void build(int node, int l, int r, vector<int> &a) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2*node, l, mid, a);
        build(2*node+1, mid+1, r, a);

        tree[node] = tree[2*node] & tree[2*node+1];
    }

    int query(int node, int l, int r, int ql, int qr) {

        if(qr < l || r < ql) 
            return INT_MAX; 

        if(ql <= l && r <= qr) 
            return tree[node];

        int mid = (l + r) / 2;

        int left = query(2*node, l, mid, ql, qr);
        int right = query(2*node+1, mid+1, r, ql, qr);

        return left & right;
    }

    int rangeAnd(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    SegTree st(a);

    int q; cin>>q;
    while(q--){
        int l, k; cin>>l>>k; l--;
        if(a[l] < k){
            cout<<-1<<" ";
            continue;
        }
        int lo = l; 
        int hi = n-1;
        int mid = lo + (hi - lo)/2;
        int ans = -1;
        while(lo <= hi){
            int left = l;
            int right = mid;
            if(st.rangeAnd(left, right) >= k){
                ans = mid;
                lo = mid+1;
            }
            else if(st.rangeAnd(left, right) < k){
                hi = mid-1;
            }
            mid = lo + (hi-lo)/2;
        }
        cout<<ans+1<<" ";
    }
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
