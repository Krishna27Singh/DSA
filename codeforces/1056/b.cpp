#include<iostream>
#include<vector>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;

        if(k==n*n-1 || k>n*n){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            cout<<"YES"<<endl;
        }

        bool n_is_even = false;
        if(n%2==0) n_is_even = true;
        bool k_is_even = false;
        if((k/n)%2==0) k_is_even = true;

        vector<vector<char> > grid(n, vector<char> (n, 'F'));

        
            for(int j = 0; j<n; j++){
                char char_to_be_inserted;
                if(j==0){
                    char_to_be_inserted = 'R';
                }
                else char_to_be_inserted = 'L';
                for(int i = 0; i<n; i++){
                    grid[i][j] = char_to_be_inserted;
                }
            } 

            if(k <= (n*n-2*n)){
                for(int j = n-1; j>1; j--){
                    for(int i = 0; i<n; i++){
                        if(k==0) break;
                        grid[i][j] = 'R';
                        k--;
                    }
                }
            }
            else{
                for(int j = n-1; j>1; j--){
                    for(int i = 0; i<n; i++){
                        grid[i][j] = 'R';
                        k--;
                    }
                }
                if(k%2==0){
                    for(int i = 0; i<n; i++){
                        for(int j = 0; j<=1; j++){
                            if(k==0) break;
                            grid[i][j] = 'U';
                            k--;
                        }
                    }
                }
                else{
                    bool check = false;
                    for(int i = 0; i<n; i++){
                        if(check) break;
                        for(int j = 0; j<=1; j++){
                            if(k==0){
                                grid[i][j] = 'D';
                                check = true;
                                break;
                            }
                            grid[i][j] = 'U';
                            k--;
                        }
                    }
                }
            }

            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    cout<<grid[i][j];
                }
                cout<<endl;
            }

        
    }

    return 0;
}