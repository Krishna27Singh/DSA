#include<iostream>
using namespace std;

long long int sqrtInt(int n){
    
    int s = 0;
    int e = n;
    long long int mid = s + (e-s)/2;

    long long int ans = -1;

    while(s<=e){

        long long square = mid*mid;

        if(square == n){
            return mid;
        }

        else if(square < n){
            ans = mid;
            s = mid + 1;
        }

        else{
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol){

    double factor = 1;
    double ans = tempSol;

    for( int i =0; i<precision; i++){
        factor = factor/10;

        for(double j = ans; j*j<n; j = j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    int precision;
    cout<<"Enter the number whose square root you want to calculate"<<endl;
    cin>>n;
    cout<<"Enter the precision of the answer"<<endl;
    cin>>precision;

    int tempSol = sqrtInt(n);
    double result = morePrecision(n, precision, tempSol);
    cout<<"The answer is "<< result<<endl;
    return 0;
}