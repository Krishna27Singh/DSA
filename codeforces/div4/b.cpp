#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int tc; 
    cin >> tc;
    while(tc--){
        long long n; 
        cin >> n;
        vector<long long> a(n);
        long long total_sum = 0;
        vector<long long> odd;



        for(int i = 0; i < n; i++) {
            cin >> a[i];
            total_sum += a[i];
            if(a[i] % 2 == 1)
                odd.push_back(a[i]);
        }

        if(odd.size()==0){
            cout<<0<<endl;
            continue;
        }

        sort(odd.begin(), odd.end());

        // If number of odd fields is even, remove the smallest odd
        // if(odd.size() % 2 == 0 && !odd.empty()) {
        //     long long min_odd = *min_element(odd.begin(), odd.end());
        //     total_sum -= min_odd;
        // }

        int it = (odd.size())/2;
        for(int i = 0; i<it; i++){
            total_sum -= odd[i];
        }

        cout << total_sum << endl;
    }

    return 0;
}
