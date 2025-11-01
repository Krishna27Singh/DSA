#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<vector<char> > grid(n, vector<char>(n, '.'));
        int total_black = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>grid[i][j];
                if(grid[i][j]=='#') total_black++;
            }
        }

        int j = 0;
        bool check = false;
        for(int i = 0; i<n; i++){
            int diagonal1_black = 0;
            int diagonal2_black = 0;

            int diag1i = i; int diag1j = 0;
            while(diag1i<n && diag1j+diag1i<n){
                if(grid[diag1i][diag1j]=='#') diagonal1_black++;
                diag1i++; diag1j++;
            }
            int diag2i = i+1; int diag2j = 0;
            while(diag2i<n && diag2j+diag2i<n){
                if(grid[diag2i][diag2j]=='#') diagonal2_black++;
                diag2i++; diag2j++;
            }

            if(diagonal1_black + diagonal2_black == total_black){
                check = true;
                break;
            }
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}