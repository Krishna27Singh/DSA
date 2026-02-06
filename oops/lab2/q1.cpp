#include<iostream>
using namespace std;

void swapByReference(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

int main(){

    int a, b; cin>>a>>b;

    cout<<"Value of a and b without swapping by reference is : "<< a<<" "<<b<<endl;
    swapByReference(a, b);
    cout<<"Value of a and b after swapping by reference is : "<<a<<" "<<b<<endl;

    return 0;
}