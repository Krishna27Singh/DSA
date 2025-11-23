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
    int n; cin>>n;
    string s; cin>>s;

    string mex = "";

    for (char c = 'a'; c <= 'z'; c++) {
			if (s.find(c) == string::npos) { 
				mex = c;
				break;
			}
	}

    for (char c1 = 'a'; c1 <= 'z'; c1++) {
			for (char c2 = 'a'; c2 <= 'z'; c2++) {
				string tmp = "";
				tmp.push_back(c1);
				tmp.push_back(c2);

				if (mex == "" && s.find(tmp) == string::npos) {
					mex = tmp;
				}
			}
		}

        for (char c1 = 'a'; c1 <= 'z'; c1++) {
			for (char c2 = 'a'; c2 <= 'z'; c2++) {
				for (char c3 = 'a'; c3 <= 'z'; c3++) {
					string tmp = "";
					tmp.push_back(c1);
					tmp.push_back(c2);
					tmp.push_back(c3);

					if (mex == "" && s.find(tmp) == string::npos) {
						mex = tmp;
					}
				}
			}
		}

        cout<<mex<<endl;
        
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
