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
#include<iomanip>
#include <array>
#include <climits>
#include <numeric>
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvld;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
typedef priority_queue<ll> mxpq;
typedef priority_queue<ll, vll, greater<ll>> mnpq;

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 998244353;

class dsu {
 public:
  vector<int> p;
  int n;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
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
int gi(const vector<pair<int, int>>& A, int x) {
    for (int i = 0; i < sz(A); ++i) {
        if (A[i].first == x) return i;
    }
    return -1;
}

int gt(const vector<pair<int, int>>& A) {
    int m1 = -1, c1 = 0, m2 = -1;
    for (int i = sz(A) - 1; i >= 0; --i) {
        if (A[i].second > 0) {
            if (m1 == -1) {
                m1 = A[i].first;
                c1 = A[i].second;
            } else if (m2 == -1) {
                m2 = A[i].first;
                break;
            }
        }
    }
    if (m2 == -1) return 0;
    if (c1 >= 2) return m1 - m2;
    return 0;
}

int gl(const vector<pair<int, int>>& A) {
    int mn1 = -1, c1 = 0, mn2 = -1;
    for (int i = 0; i < sz(A); ++i) {
        if (A[i].second > 0) {
            if (mn1 == -1) {
                mn1 = A[i].first;
                c1 = A[i].second;
            } else if (mn2 == -1) {
                mn2 = A[i].first;
                break;
            }
        }
    }
    if (mn2 == -1) return 0;
    if (c1 >= 2) return mn2 - mn1;
    return 0;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vi d(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        d[u]++; d[v]++;
    }
    vi c(n + q + 5, 0);
    set<int> p;
    for (int i = 1; i <= n; ++i) {
        if (c[d[i]] == 0) p.insert(d[i]);
        c[d[i]]++;
    }

    ll ip = modInverse(1LL * n * (n - 1) / 2 % MOD);

    for (int qi = 0; qi < q; ++qi) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            c[d[u]]--;
            if (c[d[u]] == 0) p.erase(d[u]);
            d[u]++;
            if (c[d[u]] == 0) p.insert(d[u]);
            c[d[u]]++;

            c[d[v]]--;
            if (c[d[v]] == 0) p.erase(d[v]);
            d[v]++;
            if (c[d[v]] == 0) p.insert(d[v]);
            c[d[v]]++;
        } else {
            int s; cin >> s;
            set<int> U;
            if (s == 1) {
                vi td;
                auto it = p.rbegin();
                for (int i = 0; i < 6 && it != p.rend(); ++i, ++it) td.pb(*it);
                int T = td.empty() ? 0 : td.back();
                int lim = max(0, T - 1);
                auto it2 = p.lower_bound(lim);
                while (it2 != p.end()) {
                    U.insert(*it2);
                    U.insert(*it2 + 1);
                    ++it2;
                }
            } else {
                vi ld;
                auto it = p.begin();
                for (int i = 0; i < 6 && it != p.end(); ++i, ++it) ld.pb(*it);
                int T = ld.empty() ? 0 : ld.back();
                int lim = T + 1;
                auto it2 = p.begin();
                while (it2 != p.end() && *it2 <= lim) {
                    U.insert(*it2);
                    U.insert(*it2 + 1);
                    ++it2;
                }
            }

            vector<pair<int, int>> A;
            int sA = 0;
            for (int x : U) {
                A.pb({x, c[x]});
                sA += c[x];
            }
            int B = n - sA;
            ll ans = 0;

            for (int i = 0; i < sz(A); ++i) {
                for (int j = i; j < sz(A); ++j) {
                    ll w = 0;
                    if (i == j) w = 1LL * A[i].second * (A[i].second - 1) / 2;
                    else w = 1LL * A[i].second * A[j].second;
                    
                    if (w > 0) {
                        int i1 = gi(A, A[i].first + 1);
                        int j1 = gi(A, A[j].first + 1);

                        A[i].second--; A[j].second--;
                        A[i1].second++; A[j1].second++;

                        ll val = (s == 1) ? gt(A) : gl(A);
                        ans = (ans + (w % MOD) * val) % MOD;

                        A[i].second++; A[j].second++;
                        A[i1].second--; A[j1].second--;
                    }
                }
            }

            if (B > 0) {
                for (int i = 0; i < sz(A); ++i) {
                    ll w = 1LL * A[i].second * B;
                    if (w > 0) {
                        int i1 = gi(A, A[i].first + 1);
                        A[i].second--;
                        A[i1].second++;

                        ll val = (s == 1) ? gt(A) : gl(A);
                        ans = (ans + (w % MOD) * val) % MOD;

                        A[i].second++;
                        A[i1].second--;
                    }
                }
            }

            if (B > 1) {
                ll w = 1LL * B * (B - 1) / 2;
                if (w > 0) {
                    ll val = (s == 1) ? gt(A) : gl(A);
                    ans = (ans + (w % MOD) * val) % MOD;
                }
            }

            ans = (ans * ip) % MOD;
            cout << ans << "\n";
        }
    }
}
/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}
