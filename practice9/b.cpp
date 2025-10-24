#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<climits>

int main(){

    int n, d; cin>>n>>d;
    vector<int> p(n);
    for(int i = 0; i<n; i++) cin>>p[i];

    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    int ans = 0;
    int win = 0;
    for(int i = 0; i<n; i++){
        ans += d/p[i]+1;
        win++;
        if(ans>n){
            ans -= (d/p[i] + 1);
            win--;
            break;
        }
    }

    cout<<win<<endl;
    

    return 0;
}