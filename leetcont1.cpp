#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(6);

    int n = nums.size();

        int p=-1;
        for(int i = 1; i<n; i++){
            if(nums[i]<nums[i-1]){
                p = i-1;
                break;
            }
        }

        int q = -1;
        for(int i = n-1; i>0; i--){
            if(nums[i-1]>nums[i]){
                q = i;
                break;
            }
        }

        if(p<q && p!=-1 && q!=-1) cout<<1<<endl;
        else{ cout<<0<<endl;}

    return 0;
}