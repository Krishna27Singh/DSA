#include<iostream>
using namespace std;

int peakInMountainArray(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    
    while(s<=e){

        if(arr[mid]> arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }

        else if(arr[mid]> arr[mid-1] && arr[mid]<arr[mid+1]){
            s = mid+1;
        }

        else if(arr[mid]< arr[mid-1] && arr[mid]>arr[mid+1]){
            e = mid-1;
        }

        mid = s + (e-s)/2;
    }
}

int main(){

    int arr[] = {1,2,4,6,7,11,22,33,44,5,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    int peak_index = peakInMountainArray(arr, size);

    cout<<"The peak in index is "<<peak_index<<endl;

    return 0;
}