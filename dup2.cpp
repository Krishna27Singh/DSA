#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    // cout<<"EH";
    int result = 1;
        for(int i = 1; i<nums.size(); i++){
            int count = 0;
            int NOT_EXIST = false;
            for(int j = 0; j<i; j++){
                if(nums[j]==nums[i]) count++;
                if(count>=2){
                    NOT_EXIST = true;
                    break;
                }
            }
            if(NOT_EXIST){
                for(int k = i; k<nums.size()-1; k++){
                    swap(nums[k], nums[k+1]);
                }
                i--;
            }
            else{
                result++;
            }
            for (int num : nums) {
                cout << num << " ";
            }
            cout<<endl;
            cout<<result<<endl;
        }
        cout<<result;


    return 0;
}