#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //Constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    //DESTRUCTOR
    ~Node() {
        int value = this -> data;
        //memory free
        if( this -> next != NULL){
            delete next;
            this->next = NULL;
        }

        cout<<"Memory is free for Node with data "<<value<<endl;
    }

};

void insertNode(Node* &tail, int element, int d){
    //assuming that the element is present in the list

    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    //non empty list
    else{

        Node* current = tail;

        while(current -> data != element){
            current = current -> next;
        }

        //element found -> current is pointing the element vala node
        Node* temp = new Node(d);
        temp -> next = current -> next;
        current -> next = temp;
    }
}

void print(Node* tail){

    Node* temp = tail;

    if( tail == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }

    //agar sirf ek data hoga to print nahi hoga isliye do while loop ka use krna hoga
    // while( tail -> next != temp){
    //     cout<< tail -> data << " ";
    //     tail = tail -> next;
    // }
    // cout<<endl;


    //1st APPLICATION OF DO WHILE LOOP :)))
    do{
        cout<< tail -> data <<" ";
        tail = tail -> next;
    } while(tail != temp);

    cout<<endl;
}

void deleteNode(Node* &tail, int value){

    //empty list
    if(tail == NULL){
        cout<<"The List is already empty"<<endl;
        return;
    }
    else{
        //assuming that "value" is present in the LL

        Node* prev = tail;
        Node* current = prev -> next;

        while(current -> data != value){
            prev = current;
            current = current -> next;
        }

        prev -> next = current -> next;

        //1 node case
        if(current == prev){
            tail = NULL;
        }
        // >=2 node case 
        else if(tail == current){
            tail = prev;
        }
        current -> next = NULL;
        delete current;
    }
}

int main(){

    Node* tail = NULL;

    //empty list case
    insertNode(tail, 5, 3);
    print(tail);

    /*insertNode(tail, 3, 5);
    print(tail);
    //ek node 3 dhundh ke lao and uske aage 5 daal dena

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
    */

    deleteNode(tail, 3);
    print(tail);

    return 0;
}