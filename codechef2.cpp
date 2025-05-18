#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){

    string s = "0101";
    int arr[4];
    for(int i = 0; i<s.size(); i++){
        arr[i]=int(s[i])-48;
    }
    for(int i = 0; i<4; i++){
        cout<<arr[i];
    }
}