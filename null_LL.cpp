//IF THE STARTING LINKED LIST IS NULL

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    //CONSTRUCTOR
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data<< " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int getLength(Node* head){
    Node* temp = head;
    int length = 0;

    while(temp != NULL){
        length++;
        temp = temp -> next;
    }
    return length;
}

void insertAtHead(Node* &head, Node* &tail, int d){

    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}

void insertAtTail(Node* &tail, Node* &head, int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

void insertAtPosition( Node* &head, Node* &tail, int position, int d){

    if( position ==1){
        insertAtHead(head, tail, d);
        return; //it prevents furthur execution of the function 
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    //insert at last position
    if(temp -> next == NULL){
        insertAtTail(tail, head, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout<<"The length of the linked list is: "<<getLength(head)<<endl;

    insertAtHead(head, tail, 11);
    print(head);

    insertAtHead(head, tail, 13);
    print(head);

    insertAtHead(head, tail, 17);
    print(head);

    
    insertAtTail(tail, head, 25);
    print(head);

    insertAtPosition(head, tail, 2, 100 );
    print(head);

    insertAtPosition(head, tail, 1, 101 );
    print(head);

    insertAtPosition(head, tail, 7, 102 );
    print(head);

    return 0;
}