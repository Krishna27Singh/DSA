#include<iostream>
using namespace std;

int main(){
    
    int arr[] = { 3,7, 12, 1, 19, 17};
    int n = sizeof(arr)/sizeof(arr[0]);

    for( int i =0; i< n-1; i++){
        int minIndex = i;

        for( int j =i+1; j<n; j++){
            if(arr[j]<arr[i]){
                minIndex = j;
            }
        }
        swap( arr[minIndex], arr[i]);
    }

    cout<<"The sorted array is "<<endl;
    for(int i =0; i<n; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}