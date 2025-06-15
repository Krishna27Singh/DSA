#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int num = 9288;

    string number = to_string(num);
    int n = number.size();
    char num_to_update;
    bool not_all_nine = false;

    for(int i = 0; i<n; i++){
        if(number[i]!='9'){
            num_to_update = number[i];
            not_all_nine = true;
            break;
        }
    }
    cout<<num_to_update<<endl;
    if(not_all_nine){
        for(int i = 0; i<n; i++){
            if(number[i]==num_to_update){
                number[i]='9';
            }
        }

        int maxi = stoi(number);
        cout<<maxi<<endl;
        number = to_string(num);
        cout<<number<<endl;
        if(number[0]=='1'){
            char num_to_update;
            for(int i = 1; i<n; i++){
                if(number[i]!=1 && number[i]!=0){
                    num_to_update = number[i];
                    break;
                }
            }
            cout<<num_to_update<<endl;
            for(int i = 0; i<n; i++){
                if(number[i]==num_to_update){
                    number[i]='0';
                }
            }
        }
        else{
            char num_to_update = number[0];
            for(int i = 0; i<n; i++){
                if(number[i]==num_to_update){
                    number[i]='1';
                }
            }
        }

        int mini = stoi(number);
        cout<<mini<<endl;

        int maxDiff = maxi-mini;
        cout<<maxDiff<<endl;
    }
    else{
        int maxi = stoi(number);
        for(int i = 0; i<n; i++){
            number[i]='1';
        }
        int mini = stoi(number);
        int maxDiff = maxi-mini;

        cout<<maxDiff<<endl;
    }


    return 0;
}