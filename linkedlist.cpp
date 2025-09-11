//TRAVERSE
//INSERTION AT BEGGINING
//INSERTION AT END
//INSERTION AT MID



#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
//ye Node(10) ke input ke data ko data set krdega and uske address ko null point krva dega

};

void insertAtHead(Node* &head, int d){

    //create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp; 
}

//How to print a linked list
void print(Node* head){
    Node* temp = head; //kyuki original linked list m changes nahi krna chahte

    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

void insertAtTail(Node* &tail, int d){

    //create new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
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
    temp -> next = nodeToInsert;
}

int main(){

    //created a new node
    Node* node1 = new Node(10);
    cout<< node1 -> data << endl;
    cout<< node1 -> next <<endl;

    //pointed head to new node
    Node* head = node1;
    Node* tail = node1; //single node m head and tail dono are equal
    print(head);

    // insertAtHead(head, 12);
    // print(head);

    // insertAtHead(head, 15);
    // print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    // insertAtPosition(head, 3, 17);
    insertAtPosition(head, tail, 4, 17);
    print(head);

    cout<<"Head is "<< head -> data <<endl;
    cout<<"Tail is "<< tail -> data <<endl;

    return 0;
}