#include <iostream>
#include<vector>
using namespace std;

int main() {
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> p(n); 
        for(int i=0; i<n; i++){
            cin>>p[i];
        }
        
        int answer = 0;
        
        for(int i=0; i<n; i++){
            cout<<"debug1"<<endl;
            vector<int> newp;
            newp = p;
            sort(newp.begin(), newp.end());
            if(p==newp) break;
            for(int j=0; j<n-1; j++){
                cout<<"debug2"<<endl;
                if(p[j+1]<p[j]){
                    swap(p[j+1],p[j]);
                    for(auto i: p) cout<<i;
                    int sum = p[j]+p[j+1];
                    cout<<sum;
                    answer = max(answer, sum);
                }
            }
        }
        
        cout<<answer<<endl;
    }
    return 0;
}
