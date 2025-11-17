#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <string>
using namespace std;

bool isPrime(long long n){
    if(n < 2) return false;
    for(long long i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

void solve(){
    long long d; cin >> d;
    long long p1 = d + 1;
    while(!isPrime(p1)) ++p1;
    long long p2 = p1 + d;
    while(!isPrime(p2)) ++p2;
    cout << p1 * p2 <<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
