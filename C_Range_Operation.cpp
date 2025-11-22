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
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    vector<int> prefix(n+1);
    prefix[0] = 0;
    prefix[1] = a[0];

    for(int i = 1; i<n; i++){
        prefix[i+1] = prefix[i] + a[i];
    }

    for(auto i : prefix) cout<<i<<" ";
    cout<<endl;

    int left = 0; int right = n-1;
    int ans = prefix[n];
    while(left<=right){
        int curr_sum = prefix[right+1]-prefix[left];
        int new_sum = (right-left+1)*((left+1) + (right+1));
        cout<<curr_sum<<" "<<new_sum<<endl;
        if(new_sum > curr_sum){
            int temp = new_sum;
            if(left>0) temp += prefix[left-1];
            if(right<n-1) temp += prefix[right+1];
            ans = max(ans, temp);
        }

        left++;
        curr_sum = prefix[right+1]-prefix[left];
        new_sum = (right-left+1)*((left+1) + (right+1));
        cout<<curr_sum<<" "<<new_sum<<endl;
        if(new_sum > curr_sum) ans = max(ans, new_sum);
        left--;

        right--;
        curr_sum = prefix[right+1]-prefix[left];
        new_sum = (right-left+1)*((left+1) + (right+1));
        cout<<curr_sum<<" "<<new_sum<<endl;
        if(new_sum > curr_sum){
            int temp = new_sum;
            if(left>0) temp += prefix[left-1];
            if(right<n-1) temp += prefix[right+1];
            ans = max(ans, temp);
        }

        right++;
        left++;
        right--;
    }

    cout<<ans<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
