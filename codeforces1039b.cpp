#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> p(n);
        for(int i = 0; i<n; i++) cin>>p[i];

        deque<int> dq;
        for(auto i: p){
            dq.push_back(i);
        }
        string answer="";

        int prev = p[0];
        int count = 1;

        while(!dq.empty()){
            int left = dq.front();
            int right = dq.back();

            if(count%2!=0){
                if(left<right){
                    answer.push_back('L');
                    dq.pop_front();
                }
                else{
                    answer.push_back('R');
                    dq.pop_back();
                }
            }

            else{
                if(left<right){
                    answer.push_back('R');
                    dq.pop_back();
                }
                else{
                    answer.push_back('L');
                    dq.pop_front();
                }
            }
            
            count++;
        }

        cout<<answer<<endl;

    }

    return 0;
}