#include<iostream>
#include<string>
using namespace std;

int main(){
    string s = "abcyy";
    int t = 2;
    // cout<<s.size()<<endl;
    for(int i = 0; i<t; i++){
        string new_s = "";
        for(int j = 0; j<s.size(); j++){
            if(s[j]=='z'){
                // cout<<s[j];
                new_s += "ab";
            }
            else{
                // cout<<s[j]<<endl;
                new_s = new_s + char(s[j]+1);
            }
        }
        s = new_s;
        // cout<<s<<endl;
        // cout<<new_s<<endl;
    }
    cout<<s.size();
    return 0;
}