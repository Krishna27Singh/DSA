#include<iostream>
using namespace std;

int getMax(int arr[], int size){

    int maxi = INT_MIN;

    for(int i =0; i<size; i++){

        // maxi = max(maxi, arr[i]); max is a built in funtion

        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }

    return maxi;
}

int getMin(int arr[], int size){

    int mini = INT_MAX;

    for(int i =0; i<size; i++){

        // main = min(mini, arr[i]); min is a built in funtion

        if(arr[i]<mini){
            mini = arr[i];
        }
    }

    return mini;
}

int main(){

    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int arr[100];

    cout<<"Enter the elements of the array"<<endl;

    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }

    cout<<"printing the array..."<<endl;

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<endl;
    }

    cout<<"the maximum value in the array is"<<endl<<getMax(arr, size)<<endl;
    cout<<"the minimum value in the array is"<<endl<<getMin(arr, size)<<endl;

    return 0;
}