#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){

        long long n; cin>>n;
        vector<long long> b((n*(n-1))/2);
        for(int i = 0; i < (n*(n-1))/2; i++){
            cin>>b[i];
        }
        int new_n = n;

        if(n==1){
            cout<<b[0]<<endl;
            continue;
        }
        if(n==2){
            cout<<b[0]<<" "<<b[0]+1<<endl;
            continue;
        }

        set<long long> s;
        for(auto i: b) s.insert(i);


        unordered_map<long long, long long> freq;
        for(auto i: b) freq[i]++;

        vector<long long> a;
        long long max_element = -1e8;
        for(auto i: s){
            max_element = max(max_element, i);
            long long frequency = freq[i];
            long long l = 1;
            for(; l<=n; l++){
                long long threshold = (new_n-1)*l - (l*(l-1))/2;
                
                if(frequency <= threshold){
                    // cout<<l<<" "<<threshold<<" "<<frequency<<endl;
                    break;
                }
            }
            new_n--;
            // cout<<l<<endl;
            for(long long j = 0; j<l; j++){
                a.push_back(i);
            }
        }

        if(a.size()<n){
            a.push_back(max_element );
        }
        // cout<<a.size()<<endl;
        for(auto i: a){
            cout<<i<<" ";
        }
        
        cout<<endl;

    }

    return 0;
}