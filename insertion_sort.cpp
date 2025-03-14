#include<iostream>
using namespace std;

int main(){

    int arr[] = { 3,7, 12, 1, 19, 17};
    int n = sizeof(arr)/sizeof(arr[0]);

    for( int i = 1; i<n; i++){
        int temp = arr[i];
        int j = i-1;

        for(; j>=0; j--){
            if(arr[j]>temp){
            //shift
            arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]= temp; //kyuki j hmesha ek peeche chala jayega to +1 krke assign krni pdegi value
    }

    cout<<"The sorted array is "<<endl;
    for(int i =0; i<n; i++){
        cout<<arr[i]<<endl;
    }


    return 0;
}