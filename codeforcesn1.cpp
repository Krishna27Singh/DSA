#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        string first, second, third;
        cin>>first>>second>>third;

        string answer = "";

        answer = answer + first[0];
        answer = answer + second[0];
        answer = answer + third[0];

        cout<<answer<<endl;
    }

    return 0;
}