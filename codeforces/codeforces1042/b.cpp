#include<iostream>
#include<vector>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;

        vector<int> answer;

        if(n%2==0){
            int it = (n-2)/2;
            for(int i = 0; i<it; i++){
                answer.push_back(-1);
                answer.push_back(3);
            }
            answer.push_back(-1);
            answer.push_back(2);
        }
        else{
            int it = (n-1)/2;
            for(int i = 0; i<it; i++){
                answer.push_back(-1);
                answer.push_back(3);
            }
            answer.push_back(-1);
        }

        for(auto i: answer) cout<<i<<" ";
    }

    return 0;
}