// #include<iostream>
// using namespace std;
// // void fun(int &a){
// //     a *= 10;
// //     return;
// // }

// int main(){
//     int a = 5;
//     void fun(int &a){
//         a *= 10;
//         return;
//     }
//     fun(a);
//     cout<<a;
//     return 0;
// } 

#include<iostream>
using namespace std;

void show(float a){
    cout<<"float: "<<a<<endl;
}

void show(double a){
    cout<<"double: "<<a<<endl;
}

int main(){
    show(2);
    
    return 0;
}