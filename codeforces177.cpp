// #include<iostream>
// using namespace std;

// int main(){
//     int tc; cin>>tc;
//     while(tc--){
//         int n; cin>>n;
//         cout<<2*n<<endl;
//     }
// }

#include<iostream>
using namespace std;
using ll = long long;

int main(){

    int tc; cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        ll k; 
        cin>>k;
        ll x;
        cin>>x;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        vector<int> b;
        for(int i = 0; i<k; i++){
            b.insert(b.end(), a.begin(), a.end());
        }

        int sizeb = b.size();
        vector<int> prefixSum(sizeb);

        prefixSum[0]=b[0];
        for(int i = 1; i<sizeb; i++){
            prefixSum[i]=prefixSum[i-1]+b[i];
        }

        int ans = 0;
        for(int i = 0; i<sizeb; i++){
            for(int j = 0; j<sizeb; j++){
                if(prefixSum[j]-prefixSum[i-1]>=x){
                    ans++; 
                    break;
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}