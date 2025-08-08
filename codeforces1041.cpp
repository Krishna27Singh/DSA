#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int mex(int a, int b, int c){
    vector<int> temp;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);

    sort(temp.begin(), temp.end());
    int mex;

    if(temp[0]>0) mex = 0;
    else if(temp[0]==0 && temp[1]!=1) mex = 1;
    else if(temp[0]==0 && temp[1]==1 && temp[2]!=2) mex = 2;
    else mex = 3;

    return mex;
}

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        bool check = false;

        for(int i = 0; i<n-2; i++){

            

            if(a[i]!=-1 && a[i+1]!=-1 && a[i+2]!=-1){
                int maximum = max({a[i], a[i+1], a[i+2]});
                int minimum = min({a[i], a[i+1], a[i+2]});
                bool check_if_equal = mex(a[i], a[i+1], a[i+2]) == maximum - minimum;

                

                if(!check_if_equal){
                    check = true;
                    cout<<"debug1"<<endl;
                    break;
                }
            }

            if((a[i]==-1 && a[i+1]!=-1 && a[i+2]!=-1) || (a[i]!=-1 && a[i+1]==-1 && a[i+2]!=-1) || (a[i]!=-1 && a[i+1]!=-1 && a[i+2]==-1)){
                vector<int> temp(3);
                temp.push_back(a[i]);
                temp.push_back(a[i+1]);
                temp.push_back(a[i+2]);
                int neg_idx;
                if(a[i]<0){neg_idx=i;} else if(a[i+1]<0){neg_idx=i+1;} else{neg_idx=i+2;}

                sort(temp.begin(), temp.end());
                bool check_condition = temp[1]==temp[2];

                if(!check_condition){
                    check = true;
                    cout<<"debug2"<<endl;
                    break;
                }
                else{
                    a[neg_idx]=temp[1];
                    cout<<"debug4"<<endl;
                }
            }

            if((a[i]==-1 && a[i+1]==-1 && a[i+2]!=-1) || (a[i]==-1 && a[i+1]!=-1 && a[i+2]==-1) || (a[i]!=-1 && a[i+1]==-1 && a[i+2]==-1)){
                vector<int> temp(3);
                temp.push_back(a[i]);
                temp.push_back(a[i+1]);
                temp.push_back(a[i+2]);
                int neg_idx1, neg_idx2;
                if(a[i]>=0){neg_idx1=i+1;neg_idx2=i+2;} else if(a[i+1]>=0){neg_idx1=i;neg_idx2=i+2;} else{neg_idx1=i;neg_idx2=i+1;}

                sort(temp.begin(), temp.end());
                bool check_condition = temp[2]!=0;

                if(!check_condition){
                    check = true;
                    cout<<"debug3"<<endl;
                    break;
                }
                else{
                    a[neg_idx1]=temp[2];
                    a[neg_idx2] = temp[2];
                }
            }


        }

        if(!check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}