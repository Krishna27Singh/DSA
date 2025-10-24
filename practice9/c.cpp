#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<climits>

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, x, y; cin>>n>>x>>y;

        int nox = n/x;
        int noy = n/y;

        int sum1 = 0; int value1 = n;
        int sum2 = 0; int value2 = 1;

        for(int i = 0; i<nox; i++){
            sum1 += value1;
            value1--;
        }

        for(int i = 0; i<noy; i++){
            sum2 += value2;
            value2++;
        }

        cout<<sum1 - sum2<<endl;
    }

    return 0;
}