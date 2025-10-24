#include<iostream>
using namespace std;
#include<vector>

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        int left = 1; 
        int right = n-1;
        int ansa = -1;
        int ansb = -1;

        while(left < right){
            int num1 = left;
            int num2 = right;

            if(num1%num2==0 || num2%num1==0){
                ansa = num1;
                ansb = num2;
            }
        }
    }

    return 0;
}