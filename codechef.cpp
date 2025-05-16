// #include<iostream>
// using namespace std;
// int main(){

//     int a,b,c;
//     cin>>a>>b>>c;
//     cout<<a<<b<<c;
//     return 0;
// }

// #include <bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cout<<"Enter n";
    cin>>n;
    int check = n+1;
    int answer1;
    while(true){
        if(check%3==0){
             answer1 = check;
             break;
        }
        check++;
    }
    cout<<answer1<<endl;
    check = n-1;
    int answer2;
    while(true){
        if(check%3==0){
            answer2 = check;
            break;
        }
        check--;
    }
    cout<<answer2<<endl;
    cout<<(answer1-check)<<endl;
    cout<<(answer2-check)<<endl;
    if(abs(answer1-n)<abs(answer2-n)) cout<<answer1;
    else cout<<answer2;
}