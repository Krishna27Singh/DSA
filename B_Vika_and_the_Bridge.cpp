#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <string>
using namespace std;

void solve(){
    long long n, k; cin>>n>>k;
    vector<long long> c(n);
    for(int i = 0; i<n; i++) cin>>c[i];

    int min_max_gap = 1e9;
    int min_max_gap_element;
    for(int i = 1; i<=k; i++){
        int max_gap = -1e8;
        int count = 0;
        for(int j = 0; j<n; j++){
            if(j==n-1 && c[j]!=i) count++;
            if(c[j]==i || j==n-1){
                max_gap = max(max_gap, count);
                count = 0;
            }
            else{
                count++;
            }
        }
        if(min_max_gap > max_gap){
            min_max_gap = max_gap;
            min_max_gap_element = i;
        }
    }

    vector<int> steps;
    int count = 0;
    for(int i = 0; i<n; i++){
        if(i==n-1 && c[i]!=min_max_gap_element) count++;
        if(c[i]==min_max_gap_element || i==n-1){
            steps.push_back(count);
            count = 0;
        }
        else count++;
    }

    sort(steps.begin(), steps.end());
    int final_min_max_gap = steps[steps.size()-1];

    if(final_min_max_gap%2!=0){
        steps[steps.size()-1] = final_min_max_gap/2;
        steps.push_back(final_min_max_gap/2);
    }
    else{
        steps[steps.size()-1] = final_min_max_gap/2;
        steps.push_back(final_min_max_gap/2 - 1);
    }

    sort(steps.begin(), steps.end());

    cout<<steps[steps.size()-1]<<endl;
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
