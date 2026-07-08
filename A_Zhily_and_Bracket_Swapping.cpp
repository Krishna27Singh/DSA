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

*/

/*
****************************************** Testing ****************************************************

*/

void solve(){
    int n; cin>>n;
    string a; cin>>a;
    string b; cin>>b;

    int o = 0; int c = 0;
    for(auto i: a){
        if(i == '(') o++;
        else c++;
    }
    for(auto i: b){
        if(i == '(') o++;
        else c++;
    }

    if(o != c){
        cout<<"NO"<<endl;
        return;
    }

    stack<char> st;
    for(int i = n-1; i>=0; i--){
        if(st.empty()){
            if(a[i] == ')') st.push(a[i]);
            else{
                if(b[i] == ')'){
                    swap(a[i], b[i]);
                    st.push(a[i]);
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        else{
            if(a[i] == '(') st.pop();
            else{
                if(b[i] == '('){
                    swap(a[i], b[i]);
                    st.pop();
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }

    cout<<a<<" "<<b<<endl;

    stack<char> st2;

    //check if b is a regular bracket sequence

    for(int i = n-1; i>=0; i--){
        if(st2.empty()){
            if(b[i] == ')') st2.push(b[i]);
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
        else{
            if(b[i] == '(') st2.pop();
            else st2.push(b[i]);
        }
    }



    cout<<"YES"<<endl;

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
