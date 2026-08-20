#include <iostream>
#include <vector>

using namespace std;

long long t[400005], lz[400005], h[100005];

void bd(int nd, int l, int r) {
    if (l == r) {
        t[nd] = h[l];
        return;
    }
    int m = l + (r - l) / 2;
    bd(2 * nd, l, m);
    bd(2 * nd + 1, m + 1, r);
    t[nd] = min(t[2 * nd], t[2 * nd + 1]);
}

void pd(int nd) {
    if (lz[nd] != 0) {
        lz[2 * nd] += lz[nd];
        lz[2 * nd + 1] += lz[nd];
        t[2 * nd] += lz[nd];
        t[2 * nd + 1] += lz[nd];
        lz[nd] = 0;
    }
}

void up(int nd, int l, int r, int ql, int qr, long long v) {
    if (ql <= l && r <= qr) {
        t[nd] += v;
        lz[nd] += v;
        return;
    }
    pd(nd);
    int m = l + (r - l) / 2;
    if (ql <= m) up(2 * nd, l, m, ql, qr, v);
    if (qr > m) up(2 * nd + 1, m + 1, r, ql, qr, v);
    t[nd] = min(t[2 * nd], t[2 * nd + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, q, a, b, c;
    cin >> n >> q >> a >> b >> c;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    bd(1, 1, n);
    while (q--) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            c -= a;
        } else if (ty == 2) {
            int l, r;
            cin >> l >> r;
            up(1, 1, n, l, r, -b);
        } else if (ty == 3) {
            if (t[1] > c) cout << "JOTARO\n";
            else if (t[1] == c) cout << "DRAW\n";
            else cout << "DIO\n";
        }
    }
    return 0;
}