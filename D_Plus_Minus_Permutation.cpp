#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<climits>
#include <numeric>
#include<cmath>
 
int main(){
 
    long long tc; cin>>tc;
    while(tc--){
        long long n, x, y; cin>>n>>x>>y;
 
        long long nox = n/x;
        long long noy = n/y;
 
        long long common = lcm(x,y);
        common = n/common;
 
        nox -= common;
        noy -= common;
 
 
        cout << (n*nox - (nox*(nox-1))/2 - (((noy)*(noy+1))/2)) << endl;
    }
 
    return 0;
}