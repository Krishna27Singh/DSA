#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for(int i = 0; i<len1; i++){
        first[i]=arr[k];
        k++;
    }

    k = mid+1;
    for(int i = 0; i<len2; i++){
        second[i]=arr[k];
        k++;
    }

    //merge 2 sorted array
    int idx1 = 0;
    int idx2 = 0;
    int arrIdx = s;

    while(idx1<len1 && idx2<len2){
        if(first[idx1]<second[idx2]){
            arr[arrIdx]=first[idx1];
            arrIdx++;
            idx1++;
        }
        else{
            arr[arrIdx]=second[idx2];
            arrIdx++;
            idx2++;
        }
    }

    while(idx1<len1){
        arr[arrIdx]=first[idx1];
        arrIdx++;
        idx1++;
    }

    while(idx2<len2){
        arr[arrIdx]=second[idx2];
        arrIdx++;
        idx2++;
    }
}

void mergeSort(int *arr, int s, int e){
    //base case
    if(s>=e) return;

    int mid = s + (e-s)/2;

    //sort left part
    mergeSort(arr, s, mid);

    //sort right part
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);
}

int main(){

    int arr[5] = {2,5,1,6,9};
    int n = 5;

    mergeSort(arr, 0, n-1);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}