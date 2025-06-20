#include<iostream>
#include<vector>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        int count_zeros = 0;
        for(auto i: a) if(!i) count_zeros++;

        if(count_zeros==0){
            cout<<"1"<<endl;
            cout<<"1 "<<n<<endl;
            continue;
        }

        if(count_zeros==n){
            cout<<"3"<<endl;
            cout<<"1 2"<<endl;
            cout<<"3 "<<n<<endl;
            cout<<"1 2"<<endl;
            continue;
        }

        if(count_zeros==1){
            int position;
            for(int i = 0; i<n; i++) if(!a[i]) position = i;

            if(position==n-1){
                cout<<"2"<<endl;
                cout<<n-1<<" "<<n<<endl;
                cout<<"1"<<" "<<n-1<<endl;
                continue;
            }
            
            cout<<"2"<<endl;
            cout<<position+1<<" "<<position+2<<endl;
            cout<<"1 "<<n-1<<endl;
            continue;
        }

        int position1, position2;
        for(int i = 0; i<n; i++){
            if(a[i]==0){
                position1 = i;
                break;
            }
        }
        for(int i =n-1; i>=0; i--){
            if(a[i]==0){
                position2 = i;
                break;
            }
        }

        if(position1==0 && position2==n-1){
            int non_zero;
            for(int i = 0; i<n; i++){
                if(a[i]!=0){
                    non_zero=i;
                    break;
                }
            }

            cout<<"3"<<endl;
            cout<<"1 "<<non_zero<<endl;
            cout<<non_zero+1<<" "<<n<<endl;
            cout<<"1 2"<<endl;
            continue;
        }
        else{
            cout<<"2"<<endl;
            cout<<position1+1<<" "<<position2+1<<endl;
            cout<<"1 "<<n-(position2-position1)<<endl;
            continue;
        }
    }

    return 0;
}