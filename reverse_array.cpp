#include<iostream>
using namespace std;

int main(){

    int size, arr[100];
    cout<<"Enter the size of the array you want to reverse"<<endl;
    cin>>size;
    cout<<"Enter the array you want to reverse"<<endl;
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    
    for(int i =0; i<size/2; i++){
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }

    cout<<"The reversed array is"<<endl;

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<endl;
    }


    return 0;

}