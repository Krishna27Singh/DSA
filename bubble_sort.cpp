#include<iostream>
using namespace std;

int main(){

    int arr[] = { 3,7, 12, 1, 19, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool swapped = false;

    for( int i=1; i<n; i++){ 
    //n-1 rounds ke liye

        for(int j=0; j<n-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break; //aur optimization ke liye
        }
    }

    cout<<"The sorted array is "<<endl;
    for(int i =0; i<n; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}