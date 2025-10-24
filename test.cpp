// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;


// int main(){

//     int n; cin>>n;
//     vector<int> a(n);
//     for(int i =0; i<n; i++) cin>>a[i];

//     unordered_map<int, int> mpp;
//     for(auto i: a) mpp[i]++;

//     int largest = INT_MIN;
//     int ans = 0;
//     for(auto i: mpp){
//         if(i.second>ans){
//             ans = i.second;
//             largest = i.first;
//         }
//         else if(i.second==ans){
//             if(i.first>largest) largest = i.first;
//         }
//      }

//      cout<<largest;

    

//     return 0;
// }


#include<iostream>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        string s; cin>>s;
        int n = s.size();

        int zeros = 0;
        int ones = 0;

        for(auto charr : s){
            if(charr == '0') zeros++;
            else ones++;
        }

        string t = "";

        for(int i = 0; i<n; i++){

            if((!ones && s[i]=='0') || (!zeros && s[i]=='1')){
                break;
            }

            if(s[i]=='0' && ones>0){
                t += '1';
                ones--;
            }
            else if(s[i]=='1' && zeros>0){
                t += '0';
                zeros--;
            }
        }


        cout<<s.size() - t.size()<<endl;

    }

    return 0;
}

