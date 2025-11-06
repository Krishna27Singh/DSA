#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include<unordered_set>
#include <climits>
#include <stack>
#include <string>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    // bool check = false;
    // for(auto i: a){
    //     if(i==1){
    //         check = true;
    //         break;
    //     }
    // }
    // if(check){
    //     cout<<1<<" "<<a[n-1]<<endl;
    //     return;
    // }

    // unordered_set<long long> s;
    // s.reserve(n * 2);
    // long long maxi = LLONG_MIN;
    // int cntEven = 0;
    // for(auto i: a){
    //     s.insert(i);
    //     if(i>maxi) maxi = i;
    //     if(i%2==0) cntEven++;
    // }


    // unordered_map<int, int> freq;

    // for(auto i: a) freq[i]++;
    
    // int cntEven = 0;
    // for(auto i: a){
    //     if(i%2==0) cntEven++;
    // }

    // if(cntEven>=2){
    //     int num1, num2;
    //     for(int i = 0; i<n; i++) if(a[i]%2==0) num1 = a[i];
    //     for(int i = n-1; i>=0; i++) if(a[i]%2==0) num2 = a[i];
    //     cout<<num1<<" "<<num2<<endl;
    //     return;
    // }

    // int maxi = 0;
    // for(auto i: a) if(i>maxi) maxi = i;
    // int num1, num2;
    // bool checkFinal = false;

    // for(int i = 0; i<=n-1; i++){
    //     long long x = a[i];
    //     if(x<=0) continue;
        
    //     long long qMax = maxi/x;
    //     for(int q = 1; q<=qMax; q++){
    //         for(int r = 0; r<x; r+=2){
    //             int y = x*q + r;
    //             if(y>maxi) break;
    //             if(y > x && s.find(y) != s.end()){
    //                 cout<<x<<" "<<y<<endl;
    //                 return;
    //             }
    //         }
    //     }
    // }

    bool check = false;
    int xi = -1, yj = -1;
        for (int i = 0; i < n && !check; i++) {
            for (int j = i +1; j <n && j<= i + 100; j++) {
                long long r = a[j] % a[i];
                if ((r%2) == 0) {
                    xi = i; yj = j;
                    check = true;
                    break;
                }
            }
        }   
    
    if(check){
        cout<<a[xi]<<" "<<a[yj]<<endl;
        return;
    }

    cout<<-1<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
