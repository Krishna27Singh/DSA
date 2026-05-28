#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int beauty;
    char lCol;
    char rCol;
    char lazy;
};

vector<Node> seg;

Node mergeNodes(const Node& a, const Node& b) {
    Node res;
    res.beauty = a.beauty + b.beauty;
    if (a.rCol != b.lCol && a.rCol != 0 && b.lCol != 0) {
        res.beauty++;
    }
    res.lCol = a.lCol;
    res.rCol = b.rCol;
    res.lazy = 0;
    return res;
}

void applyNode(int node, char c) {
    seg[node].beauty = 0; 
    seg[node].lCol = c;
    seg[node].rCol = c;
    seg[node].lazy = c;
}

void pushDown(int node) {
    if (seg[node].lazy != 0) {
        applyNode(2 * node, seg[node].lazy);
        applyNode(2 * node + 1, seg[node].lazy);
        seg[node].lazy = 0;
    }
}

void buildSeg(int node, int start, int end, const string& s) {
    if (start == end) {
        seg[node].beauty = 0;
        seg[node].lCol = s[start];
        seg[node].rCol = s[start];
        seg[node].lazy = 0;
        return;
    }
    int mid = start + (end - start) / 2;
    buildSeg(2 * node, start, mid, s);
    buildSeg(2 * node + 1, mid + 1, end, s);
    seg[node] = mergeNodes(seg[2 * node], seg[2 * node + 1]);
}

void updateSeg(int node, int start, int end, int l, int r, char c) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        applyNode(node, c);
        return;
    }
    pushDown(node);
    int mid = start + (end - start) / 2;
    updateSeg(2 * node, start, mid, l, r, c);
    updateSeg(2 * node + 1, mid + 1, end, l, r, c);
    seg[node] = mergeNodes(seg[2 * node], seg[2 * node + 1]);
}

int PictureNumber(int N, int M, string P, vector<int>& L, vector<int>& R, vector<char>& C) {
    if (N == 0) return 0;
    
    seg.assign(4 * N + 1, Node{0, 0, 0, 0});
    buildSeg(1, 0, N - 1, P);

    vector<int> bts;
    bts.reserve(M + 1);
    bts.push_back(seg[1].beauty); 

    for (int i = 0; i < M; i++) {
        int l = min(L[i], R[i]) - 1;
        int r = max(L[i], R[i]) - 1;
        
        l = max(0, min(l, N - 1));
        r = max(0, min(r, N - 1));

        updateSeg(1, 0, N - 1, l, r, C[i]);
        bts.push_back(seg[1].beauty);
    }

    vector<int> lis;
    lis.push_back(bts[0]);
    
    for (int i = 1; i <= M; i++) {
        if (bts[i] > bts[0]) {
            if (lis.back() < bts[i]) {
                lis.push_back(bts[i]);
            } else {
                auto it = lower_bound(lis.begin(), lis.end(), bts[i]);
                if (it != lis.end()) {
                    *it = bts[i];
                }
            }
        }
    }
    
    return lis.size();
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    string P;
    cin >> P;

    vector<int> L(M), R(M);
    vector<char> C(M);

    for (int i = 0; i < M; i++) cin >> L[i];
    for (int i = 0; i < M; i++) cin >> R[i];
    for (int i = 0; i < M; i++) cin >> C[i];

    cout << PictureNumber(N, M, P, L, R, C) << "\n";

    return 0;
}