#include<iostream>
using namespace std;

    int BinarySearch(int arr[], int size, int key){
        int start = 0;
        int end = size-1;

        int mid = start + (end-start)/2;

        while(start<=end){

            if(arr[mid]==key){
                return mid;
            }

            if(arr[mid]>key){
                end = mid-1;
            }

            if(arr[mid]<key){
                start = mid+1;
            }

            mid = start + (end-start)/2;

        }
        
        return -1;
    }

int main(){

    int arr[10] = { 2,6,29,34,44,54,62,82, 99, 121};
    int size = sizeof(arr)/sizeof(arr[0]);

    int key;
    cout<<"Enter the key to search in the array"<<endl;
    cin>>key;

    cout<<"The key "<<key<<" is present at the "<<BinarySearch(arr, size, key)<<" index of the array ";

    return 0;
}