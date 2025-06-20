#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        string s; cin>>s;

        string news = s;
        sort(news.begin(), news.end());
        if(news[news.size()-1]-news[0]==0){
            cout<<"NO"<<endl;
            continue;
        }

        if(s.size()==1){
            cout<<"NO"<<endl;
            continue;
        }

        string revs = s;
        reverse(revs.begin(), revs.end());

        if(s<revs){
            cout<<"YES"<<endl;
            continue;
        }

        if(k>0){
            //finding smallest characted in the string
            // char smallest_chr = s[0];
            // int idx = 0;
            // int n = s.size();
            // for(int i = 1; i<n; i++){
            //     if(s[i]<smallest_chr) {
            //         smallest_chr = s[i];
            //         idx = i;
            //     }
            // }

            // //swapping s[0] and smallest_chr
            // swap(s[0], s[idx]);
            cout<<"YES"<<endl;

        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}