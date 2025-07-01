// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int main(){

//     int tc; cin>>tc;
//     while(tc--){
//         int n, j, k; cin>>n>>j>>k;
//         vector<int> a(n); for(int i = 0; i<n; i++) cin>>a[i];

//         vector<int> dup(a.begin(), a.end());
//         sort(dup.begin(), dup.end());
//         if(k==1) {
//             if(dup[n-1]==a[j-1]) cout<<"YES"<<endl;
//             else cout<<"NO"<<endl;
//             continue;
//         }

//         cout<<"YES"<<endl;
//     }

//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;

// int prefix(vector<int> nums){

// }

// int main(){

//     int tc; cin>>tc;
//     while(tc--){
//         int n; cin>>n;
//         vector<int> a(n); for(int i = 0; i<n; i++) cin>>a[i];
//         vector<int> temp(a.begin(), a.end());

//         sort(temp.begin(), temp.end());
//         int mini = temp[0];
//         int maxi = temp[n-1];

//         string answer = "";

//         for(int i = 0; i<n; i++){
//             if(i==0 || i==n-1 || a[i]==maxi || a[i]==mini){
//                  answer += '1';
//                  continue;
//             }
//             else{
//                  answer += '0';
//                  continue;
//             }

            

//         }

//         cout<<answer<<endl;;
//     }

//     return 0;
// }

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        string result(n, '0');
        
        vector<int> prefix_min(n), suffix_max(n);
        prefix_min[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix_min[i] = min(prefix_min[i-1], a[i]);
        }
        suffix_max[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i+1], a[i]);
        }
        
        int global_min = prefix_min[n-1];
        int global_max = suffix_max[0];
        
        for (int i = 0; i < n; i++) {
            if (a[i] == global_min || a[i] == global_max) {
                result[i] = '1';
                continue;
            }
            
            if (i == 0) {
                if (n > 1 && a[0] <= suffix_max[1]) {
                    result[i] = '1';
                }
            } else if (i == n - 1) {
                if (a[n-1] >= prefix_min[n-2]) {
                    result[i] = '1';
                }
            } else {
                int left_min = prefix_min[i-1];
                int right_max = suffix_max[i+1];
                
                if ((a[i] <= left_min && a[i] <= right_max) || 
                    (a[i] >= left_min && a[i] >= right_max)) {
                    result[i] = '1';
                }
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
