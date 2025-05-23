// #include <iostream>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         int result = n * n / 4 + 1;
//         cout << result << endl;
//     }
//     return 0;
// }


#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int calc_gcd(vector<int> nums){
    int n = nums.size();
    int result = nums[0];

    for(int i = 0; i<n; i++){
        result = gcd(result, nums[i]);
    }

    return result;
}

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++){cin>>a[i];};
        bool yes = false;

        for(int i = 0; i<n; i++){
            int gcd1 = a[i];
            vector<int> vec1(a.begin(), a.begin()+i);
            vector<int> vec2(a.begin()+i, a.end());

            vector<int> nums(vec1.size() + vec2.size());
            copy(vec1.begin(), vec1.end(),nums.begin());
            copy(vec2.begin(), vec2.end(), nums.begin() + vec1.size());

            int gcd2 = calc_gcd(nums);

            if(gcd1!=gcd2){
                cout<<"YES"<<endl;
                for(int j = 0; j<i; j++){
                    cout<<1<<" ";
                }
                cout<<2<<" ";
                for(int j = i+1; j<n; j++){
                    cout<<1<<" ";
                }
                yes = true;
                break;
            }
        }
        if(!yes) cout<<"NO"<<endl;
    }

    return 0;
}