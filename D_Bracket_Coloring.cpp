#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
#include <numeric>
#include<stack>
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;

/*
****************************************** APPROACH **************************************************
minimum number of colors such that 
the order of every color should be beautiful 

*/

/*
****************************************** Testing ****************************************************
()() -> )()(
(()) -> ))((
)))((( -> ((()))
))()(( -> (()())

((())))( -> ())))(((


*/

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    string srev = s;
    reverse(srev.begin(), srev.end());
    
    int cntOpen = 0;
    int cntClose = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '(') cntOpen++;
        else cntClose++;
    }

    if(cntOpen != cntClose){
        cout<<-1<<endl;
        return;
    }

    stack<char> st;
    st.push(s[n-1]);
    for(int i = n-2; i>=0; i--){
        if(s[i] == ')') st.push(s[i]);
        else{
            if(st.empty()){
                st.push('(');
                break;
            }
            else st.pop();
        }
    }
    if(st.empty()){
        cout<<1<<endl;
        for(int i = 0; i<n; i++) cout<<1<<" ";
        cout<<endl;
        return;
    }
    while(!st.empty()) st.pop();
    st.push(srev[n-1]);
    for(int i = n-2; i>=0; i--){
        if(srev[i] == ')') st.push(srev[i]);
        else{
            if(st.empty()){
                st.push('(');
                break;
            }
            else st.pop();
        }
    }
    if(st.empty()){
        cout<<1<<endl;
        for(int i = 0; i<n; i++) cout<<1<<" ";
        cout<<endl;
        return;
    }

    vector<int> ans(n, 1);
    for(int i = 0; i<n-1; i++){
        if(s[i] == ')' && s[i+1] == '('){
            ans[i] = 2;
            break;
        }
    }
    for(int i = n-1; i>=1; i--){
        if(s[i] == '(' && s[i-1] == ')'){
            ans[i] = 2;
            break;
        } 
    }

    cout<<2<<endl;
    for(auto i: ans) cout<<i<<" ";
    cout<<endl;

    // Output


}

/*************************************************************************************************** */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
