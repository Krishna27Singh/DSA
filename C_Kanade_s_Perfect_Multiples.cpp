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

set<int>s;
map<int,int>u;
const int mxn=2e5+5;
int n,a[mxn],k;
void solve(){
	s.clear(),u.clear();
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],s.insert(a[i]),u[a[i]]=1;
	vector<int>ans;ans.clear();
	while(s.size()){
		int t=*s.begin();
		ans.push_back(t);
		s.erase(s.begin());
		for(int cur=t;cur<=k;cur+=t){
			if(!u[cur]){
				cout<<"-1\n";
				return;
			}
			auto t=s.find(cur);
			if(t!=s.end())s.erase(t);
		}
	}
	cout<<ans.size()<<'\n';
	for(int i:ans)cout<<i<<' ';cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
