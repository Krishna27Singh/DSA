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

class DisjointSet{
    vector<int> rank, parent, size;
public: 
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++) parent[i] = i;
    }
    int findUltimateParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ultimateParentOfU = findUltimateParent(u);
        int ultimateParentOfV = findUltimateParent(v);
        if(ultimateParentOfU == ultimateParentOfV) return; 
        if(rank[ultimateParentOfU] < rank[ultimateParentOfV]) parent[ultimateParentOfU] = ultimateParentOfV;
        else if(rank[ultimateParentOfV] < rank[ultimateParentOfU]) parent[ultimateParentOfV] = ultimateParentOfU;
        else{
            parent[ultimateParentOfV] = ultimateParentOfU; 
            rank[ultimateParentOfU]++; 
        }
    }
    void unionBySize(int u, int v){
            int ultimateParentOfU = findUltimateParent(u);
            int ultimateParentOfV = findUltimateParent(v);
            if(ultimateParentOfU == ultimateParentOfV) return; 
            if(size[ultimateParentOfU] < size[ultimateParentOfV]){
                parent[ultimateParentOfU] = ultimateParentOfV;
                size[ultimateParentOfV] += size[ultimateParentOfU];
            }
            else{ 
                parent[ultimateParentOfV] = ultimateParentOfU;
                size[ultimateParentOfU] += size[ultimateParentOfV];
            }
        }
};
struct FenwickTree {
    int n;
    std::vector<long long> tree;
    FenwickTree(int n) {
        this->n = n;
        tree.assign(n + 1, 0);
    }
    FenwickTree(const std::vector<long long>& a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; i++) {
            tree[i + 1] += a[i];
            int parent = (i + 1) + ((i + 1) & -(i + 1));
            if (parent <= n) tree[parent] += tree[i + 1];
        }
    }
    void add(int i, long long val) {
        for (i++; i <= n; i += (i & -i)) tree[i] += val;
    }
    long long sum(int i) {
        long long s = 0;
        for (i++; i > 0; i -= (i & -i)) s += tree[i];
        return s;
    }
    long long sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
    int lower_bound(long long k) {
        int curr = 0;
        long long prevsum = 0;
        int logn = 0;
        while ((1 << (logn + 1)) <= n) logn++;
        for (int i = logn; i >= 0; i--) {
            int next_pos = curr + (1 << i);
            if (next_pos <= n && tree[next_pos] + prevsum < k) {
                curr = next_pos;
                prevsum += tree[next_pos];
            }
        }
        return curr; 
    }
};
struct SegmentTree {
    int n;
    vector<long long> tree;
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }
    SegmentTree(const std::vector<long long>& a) : SegmentTree(a.size()) {
        build(a, 1, 0, n - 1);
    }
    void build(const std::vector<long long>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(a, 2 * node, start, mid);
        build(a, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val; 
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int idx, long long val) {
        update(1, 0, n - 1, idx, val);
    }
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; 
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        long long left_res = query(2 * node, start, mid, l, r);
        long long right_res = query(2 * node + 1, mid + 1, end, l, r);
        return left_res + right_res; 
    }
    long long query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};
ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
ll modInverse(ll a) {
    return binpow(a, MOD - 2);
}
bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
void buildFact(int n, vector<ll> &fact, vector<ll> &invFact) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    invFact[n] = modInverse(fact[n]);
    for (int i = n; i >= 1; i--) invFact[i - 1] = invFact[i] * i % MOD;
}
ll nCr(int n, int r, vector<ll> &fact, vector<ll> &invFact) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
ll phi(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
void linearSieve(int N, vector<int>& primes, vector<int>& spf) {
    primes.clear();
    spf.assign(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (1LL * p * i > N) break;
            spf[p * i] = p;
            if (p == spf[i]) break;
        }
    }
}

/*
****************************************** APPROACH **************************************************

*/

/*
****************************************** Testing ****************************************************

*/

int maxi(int U, int V, int K, int O, int Z) {
    int H = min(O, Z);
    int tl = max(0, H - K);
    int tr = max(0, max(O, Z) - K);
    if (V < tl) return V + K;
    else if (U > tr) return O + Z - K - U;
    else return H;
}
int mini(int U, int V, int K) {
    if (K >= U && K <= V) {
        return 0;
    }
    return min(abs(U - K), abs(V - K));
}

void solve(){
    int n, k; cin>>n>>k;
    string a; cin>>a;
    int O = 0, Z = 0;
    for (auto c : a) {
        if (c == '1') O++;
        else Z++;
    }
    
    if (k > min(O, Z)) {
        cout << a << "\n";
        cout << 0 << "\n";
        return;
    }
    
    if (k == O && k == Z) {
        string tempa = a;
        for (auto &c : tempa) {
            c = (c == '0' ? '1' : '0');
        }
        if (a <= tempa) {
            cout << a << "\n";
            cout << 0 << "\n";
        } else {
            cout << tempa << "\n";
            cout << 1 << "\n";
        }
        return;
    }
    
    string g = string(Z, '0') + string(O, '1');
    cout << g << "\n";
    
    int l = 0;
    for (int i = 0; i < Z; i++) {
        if (a[i] == '1') l++;
    }
    
    int U = l, V = l;
    int cnt = 0;
    while (U > 0) {
        int tempu = mini(U, V, k);
        int tempv = maxi(U, V, k, O, Z);
        U = tempu;
        V = tempv;
        cnt++;
    }
    cout << cnt << "\n";

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1; cin >> tc;
    while (tc--) solve();
    return 0;
}

