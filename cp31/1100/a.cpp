#include<iostream>
#include<set>
using namespace std;

void solve(string str, set<string> &stt){
    stt.insert(str);
    if(str.size()<=1) return;
    string remove_first = "";
    string remove_second = "";

    if(str.size()<=2){
        remove_first = str[1];
        remove_second = str[0];
    }
    else{
        remove_first = str.substr(1);
        remove_second = str[0] + str.substr(2);
    }

    solve(remove_first, stt);

    solve(remove_second, stt);

}

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        string s; cin>>s;

        set<string> stt;

        solve(s, stt);

        cout<<stt.size()<<endl;

    }

    return 0;
}