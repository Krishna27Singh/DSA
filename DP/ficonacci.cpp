#include<iostream>
using namespace std;

//********** MEMOIZATION ********** */

// int f(int n, vector<int> &dp){
//     if(n<=1) return n;

//     //step2:
//     if(dp[n]!=-1) return dp[n];

//     //step3
//     return dp[n]=f(n-1, dp)+f(n-2, dp);
// }

// int main(){

//     int n; cin>>n;
//     //step1:
//     vector<int> dp(n+1, -1);
//     cout<<f(n,dp);

//     return 0;
// }

//********** TABULATION ********** */

// int main(){
//     int n; cin>>n;
//     vector<int> dp(n+1);
//     dp[0]=0; dp[1]=1; //base case;
//     for(int i = 2; i<=n; i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }

//     cout<<dp[n]<<endl;
//     return 0;
// }

//********** SPACE OPTIMISATION ********** */

int main(){
    int n; cin>>n;
    int prev2=0; int prev=1; //base case;
    int curi = prev+prev2;
    for(int i = 2; i<=n; i++){
        curi = prev+prev2;
        prev2=prev;
        prev=curi;
    }

    cout<<prev<<endl;
    return 0;
}