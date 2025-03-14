#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number, you want to check is palindrome or not"<<endl;
    cin>>n;
    int ans = 0;
    while(n != 0){
        int digit = n%10;
        ans = (ans*10)+digit;
        n = n/10;

    }

    if(n==ans){
        cout<<"it is a palindrome"<<endl;
    }

    else{
        cout<<"it is not";
    }

    return 0;
}