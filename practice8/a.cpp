#include<iostream>
using namespace std;
#include<vector>

int main(){

    int tc; cin>>tc;
    while(tc--){
        vector<vector<int>> grid(10, vector<int>(10, 0));
        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++){
                cin>>grid[i][j];
            }
        }

        vector<vector<int>> values(10, vector<int>(10, 0));
        int value = 1;
        for(int i = 0; i<10; i++) values[i][0] = value;
        for(int j = 0; j<10; j++) values[0][j] = value;
        for(int i = 0; i<10; i++) values[i][9] = value;
        for(int j = 0; j<10; j++) values[9][j] = value;
        value++;
        for(int i = 1; i<9; i++) values[i][1] = value;
        for(int j = 1; j<9; j++) values[1][j] = value;
        for(int i = 1; i<9; i++) values[i][8] = value;
        for(int j = 1; j<9; j++) values[8][j] = value;
        value++;
        for(int i = 2; i<8; i++) values[i][2] = value;
        for(int j = 2; j<8; j++) values[2][j] = value;
        for(int i = 2; i<8; i++) values[i][7] = value;
        for(int j = 2; j<8; j++) values[7][j] = value;
        value++;
        for(int i = 3; i<7; i++) values[i][3] = value;
        for(int j = 3; j<7; j++) values[3][j] = value;
        for(int i = 3; i<7; i++) values[i][6] = value;
        for(int j = 3; j<7; j++) values[6][j] = value;
        value++;
        for(int i = 4; i<6; i++) values[i][4] = value;
        for(int j = 4; j<6; j++) values[4][j] = value;
        for(int i = 4; i<6; i++) values[i][5] = value;
        for(int j = 4; j<6; j++) values[5][j] = value;

        int ans = 0;

        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++){
                if(grid[i][j]=='X'){
                    ans += values[i][j];
                }
            }
        }

        cout<<ans<<endl;

    }

    return 0;
}