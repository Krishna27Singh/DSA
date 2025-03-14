#include<iostream>
using namespace std;

int main(){

    int arr[] = {1, 2, 3, 4, 2, 2, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int check[100] = {0};
    int arr1[100] = {0};
    int k =0;
    
    for( int i = 0; i <n ; i++){

        if(check[i]){
            continue;
        }

        int count = 1;

        for(int j = i+1; j<n; j++){
            if(arr[j]==arr[i]){
                count++;
                check[j] = 1;
            }
        


        }
        cout<<arr[i]<<" occurs "<<count<<" times "<<endl; 
        arr1[k] = count;
        k++;
    }

    for(int i =0; i<k; i++){
        cout<<arr1[i]<<endl;
    }

    int check1[100]={0};
    int n1=0;

    for(int i=0; ;i++){
        if(arr1[i]==0){
            break;
        }
        n1++;
    }

    cout<<n1;

    bool b = true;

    for( int i = 0; i <n1 ; i++){

        if(check1[i]){
            continue;
        }

        // int count = 1;

        for(int j = i+1; j<n1; j++){
            if(arr1[j]==arr1[i]){
                // count++;
                // check[j] = 1;
                b = false;
                break;
            }
        


        }
        // cout<<arr[i]<<" occurs "<<count<<" times "<<endl; 
        // arr1[k] = count;
        // k++;
    }

    if(b){
        cout<<"each number of occ are unique"<<endl;
    }

    else{
        cout<<"each num of occ are not unique";
    }

    return 0;
}