#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){

    string formula = "H2So4Mno2K4Coo4";

    int n = formula.size();
    unordered_map<string, int> mpp;

    int left = 0;
    int right = 0;

    while(left<n-1){
        while((formula[right]>='a' && formula[right]<='z') || (formula[right]>='A' && formula[right]<='Z')) right++;

        string entry = formula.substr(left, right-left);

        mpp[entry] = int(formula[right]-48);

        left = right+1;
        right = left;
    }

    for(const auto &pair: mpp){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    return 0;
}