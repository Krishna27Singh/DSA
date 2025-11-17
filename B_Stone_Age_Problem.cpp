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
    int n, q;
	cin >> n >> q;

	vector<pair<int, int>> v(n, {0, 0});

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
	} 

	pair<int, int> globalVal = {0, -1};

	long long sum = 0;
	for (int i = 0; i < n; i++) 
		sum += v[i].first;

	for (int it = 1; it <= q; it++)
	{
		int x;
		cin >> x;

		if (x == 1)
		{
			int ind, val;
			cin >> ind >> val;

			ind--;

			if (v[ind].second > globalVal.second)
			{
				sum += (val - v[ind].first);
			}
			else
			{
				sum += (val - globalVal.first);
			}

			v[ind].first = val;
			v[ind].second = it;
		}
		else
		{
			int val;
			cin >> val;

			globalVal.first = val;
			globalVal.second = it;

			sum = (long long)(val) * n;
		}

		cout << sum << "\n";
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
