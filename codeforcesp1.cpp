// #include<iostream>
// using namespace std;

// int main(){

//     int tc; cin>>tc;
//     while(tc--){
//         int n,m,l,r; cin>>n>>m>>l>>r;

//         if(n==m){
//             cout<<l<<" "<<r<<endl;
//             continue;
//         }

//         cout<<l<<" "<<l+m<<endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include<vector>
// #include<string>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
//         int n;
//         cin >> n;
        
//         vector<string> operations;
        
//         // For each row i from 2 to n, apply the transformation pattern
//         for (int i = 2; i <= n; i++) {
//             if (i == 2) {
//                 // Row 2: reverse entire row, then reverse from position 2 to end
//                 operations.push_back("2 1 " + to_string(n));
//                 if (n > 1) {
//                     operations.push_back("2 2 " + to_string(n));
//                 }
//             } else {
//                 // Row i (i≥3): reverse first i-1 elements, then reverse from i-1 to end
//                 operations.push_back(to_string(i) + " 1 " + to_string(i-1));
//                 if (i-1 < n) {
//                     operations.push_back(to_string(i) + " " + to_string(i-1) + " " + to_string(n));
//                 }
//             }
//         }
        
//         cout << operations.size() << "\n";
//         for (const string& op : operations) {
//             cout << op << "\n";
//         }
//     }
    
//     return 0;
// }

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        vector<long long> p(n), d(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> d[i];
        
        // Map position to light delay for O(1) lookup
        unordered_map<long long, long long> light_delay;
        for(int i = 0; i < n; i++) {
            light_delay[p[i]] = d[i];
        }
        
        int q;
        cin >> q;
        
        while(q--) {
            long long start;
            cin >> start;
            
            long long pos = start;
            int dir = 1; // 1 = right, -1 = left
            long long time = 0;
            
            set<tuple<long long, int, long long> > visited;
            bool escaped = false;
            
            const long long STRIP_SIZE = 1000000000000000LL; // 10^15
            const long long MAX_STEPS = min(4LL * k, 2000000LL); // reasonable bound
            
            for(long long step = 0; step < MAX_STEPS; step++) {
                // Check if escaped the strip
                if(pos < 1 || pos > STRIP_SIZE) {
                    escaped = true;
                    break;
                }
                
                // Check for cycle: (position, direction, time % k)
                auto state = make_tuple(pos, dir, time % k);
                if(visited.count(state)) {
                    break; // cycle detected, will never escape
                }
                visited.insert(state);
                
                // Check if current position has red light
                bool red = false;
                if(light_delay.count(pos) && time % k == light_delay[pos] % k) {
                    red = true;
                }
                
                // Turn around if red light
                if(red) {
                    dir = -dir;
                }
                
                // Move one step in current direction
                pos += dir;
                time++;
            }
            
            cout << (escaped ? "YES" : "NO") << "\n";
        }
    }
    
    return 0;
}
