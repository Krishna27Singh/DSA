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
