#include<iostream>
#include<vector>

using namespace std;
int main (){
    vector<int> v;
    v.push_back(6);
    v.push_back(2);
    v.push_back(4);
    v.push_back(67);
    v.push_back(32);
    v.push_back(40);
    v.push_back(14);
    cout <<v.size()<<" "<<v.capacity()<<endl;
    for (int i=0;i<v.size();i++){
        cout <<v[i]<<" ";
    }
    reverse(v.begin(),v.end());
    cout<<endl<<endl;
    cout<<"after reversing "<<endl;
    
    for (int i=0;i<v.size();i++){
        cout <<v[i]<<" ";
    }
    cout<<endl<<endl;
    cout <<"after sorting"<<endl;
    
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        cout <<v[i]<<" ";
    }
    
    
    return 0;
}