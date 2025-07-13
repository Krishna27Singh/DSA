#include<iostream>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans){
    if(index>=str.length()){
        if(output.size()>0){
        ans.push_back(output);
        }
        return;
    }

    solve(str, output , index+1, ans);

    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);
}

int main(){

    string str = "abc";
    vector<string> ans;
    int index = 0;
    string output = "";

    solve(str, output ,index, ans);

    for(auto i: ans){
        cout<<i<<endl;
    }

    // string str = "1101010001100";
    // reverse(str.begin(), str.end());
    // int temp = 1;
    // int answer = 0;
    // cout<<str<<endl;
    // for(int i = 0; i<str.size(); i++){
    //     if(str[i]=='1'){
    //         answer += temp;
    //         cout<<answer<<endl;
    //     }
    //     temp = temp*2;
    // }

    // cout<<answer<<endl;

    return 0;
}

