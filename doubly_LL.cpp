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

    //DESTRUCTOR
    ~Node() {
        int value = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }

        cout<<"Memeory is free for Node with data "<< value<< endl;
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

void insertAtHead(Node* &head, int d){

    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;

}

void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;

}

void insertAtPosition( Node* &head, Node* &tail, int position, int d){

    if( position ==1){
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(int position, Node* &head){

    //deleting starting node
    if(position ==1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{

        Node* current = head;
        Node* previous = NULL;

        int count = 1;
        while(count < position){
            previous = current;
            current = current -> next;
            count++;
        }
        
        current -> prev = NULL;
        previous -> next = current -> next;
        current -> next = NULL;

        delete current;
    }
}



int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<"The length of the linked list is: "<<getLength(head)<<endl;

    insertAtHead(head, 11);
    print(head);

    insertAtHead(head, 13);
    print(head);

    insertAtHead(head, 17);
    print(head);

    
    insertAtTail(tail, 25);
    print(head);

    insertAtPosition(head, tail, 2, 100 );
    print(head);

    insertAtPosition(head, tail, 1, 101 );
    print(head);

    insertAtPosition(head, tail, 8, 102 );
    print(head);

    deleteNode(8, head);
    print(head);

    return 0;
}