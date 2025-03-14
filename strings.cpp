#include<iostream>
using namespace std;

int main(){

    string s = "kri\0shna";
    char str[10] = {'k', 'r', 'i', '\0', 's', 'h', 'n', 'a'};
    cout<<s<<endl;
    cout<<str;
    //string is dynamic in nature but chrctr array is not

}