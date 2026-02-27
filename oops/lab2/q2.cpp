#include<iostream>
using namespace std;

struct Array{
    int arr[20] = {0};
};

int sizee = 0;
unordered_map<int, int> deleted;

void Setter(int val, struct Array &A1){
    if(sizee>=20){
        cout<<"out of bound "<<endl;
        return;
    }
    A1.arr[sizee] = val;
    sizee++; 
}

int Getter(int idx, struct Array &A1){
    if(idx>=sizee){
        cout<<"out of bounds "<<endl;
        return -1;
    }
    int del = 0;
    for(int i = 0; i<idx; i++){
        if(deleted.find(i) != deleted.end()) del++;
    }
    idx += del;
    return A1.arr[idx];
}

void InsertAtIndex(int idx, int val, struct Array &A1){
    if(idx >= sizee){
        cout<<"out of bounds "<<endl;
        return;
    }
    int del = 0;
    for(int i = 0; i<idx; i++){
        if(deleted.find(i) != deleted.end()) del++;
    }
    idx += del;
    A1.arr[idx] = val;
}

void DeleteAtIndex(int idx, struct Array &A1){
    if(idx >= sizee){
        cout<<"can't delete out of bounds "<<endl;
        return;
    }
    deleted[idx] = 1;
}

void print(struct Array &A1){
    for(int i = 0; i<sizee; i++){
        if(deleted.find(i) == deleted.end()) cout<<A1.arr[i]<<" ";
    }
    cout<<endl;
        return;
}



int main(){

    struct Array A1;

    Setter(2, A1);
    Setter(4, A1);
    Setter(1, A1);
    Setter(6, A1);
    Setter(8, A1);
    Setter(3, A1);
    Setter(6, A1);

    print(A1);

    DeleteAtIndex(2, A1);

    print(A1);

    cout<<Getter(4, A1)<<endl;

    InsertAtIndex(3, 10, A1);

    print(A1);

    DeleteAtIndex(0, A1);

    print(A1);

    int arr[10];
    arr[0] = 1;
    arr[1] = 4;
    arr[2] = 1;
    arr[3] = 6;
    arr[4] = 4;

    // 0 1 2 3 4 5

    int idx = 3;

    


    return 0;
}