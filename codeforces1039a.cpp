#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int n, int &answer, int c, vector<int> &arr){
    if (n == 0) return;
    if (n == 1) {
        if (arr[0] > c) answer += 1;
        return;
    }

    int pivot = n-1;
    for(; pivot>=0; pivot--){
        if(arr[pivot]<=c) break;
        answer += 1;
    }

    if(pivot == -1) return;

    vector<int> sub(arr.begin(), arr.begin()+pivot);
    for(auto &i: sub) i=i*2;
    solve(pivot, answer, c, sub);
}

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, c; cin>>n>>c;
        vector<int> weight(n);
        for(int i = 0; i<n; i++) cin>>weight[i];

        sort(weight.begin(), weight.end());

        int answer = 0;
        solve(n, answer, c, weight);

        cout<<answer<<endl;

    }

    return 0;
}