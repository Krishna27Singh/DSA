#include<iostream>
#include<vector>
using namespace std;

int main() {

    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int number_of_players;
        cin>>number_of_players;
        vector<int> report;

        for(int j = 0; j<number_of_players; j++){
            int num;
            cin>>num;
            report.push_back(num);
        }

        int duels = number_of_players-1;
        int count_wins = 0;
        int count_loss = 0;
        bool check = false;
        for(int i = 0; i<report.size(); i++){
            if(!report[i] && i!= report.size()-1){
                if(!report[i+1]){
                    check = true;
                }
            }
            if(report[i]) count_wins++;
            else count_loss++;
        }
        if((count_wins>duels || count_loss>duels)) cout<<"YES"<<endl;
        else if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}