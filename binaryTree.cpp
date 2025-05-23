#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data==-1) return NULL;

    cout<<"Enter the data for inserting in left node of "<<data<<endl;
    root -> left = buildTree(root->left);
    cout<<"Enter the data for inserting in right node of "<<data<<endl;
    root -> right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL); //we are using null as a sepearator for better printing of tree

    while(!q.empty()){
        node* temp = q.front();
        //cout<<temp->data<<" "; yaha print ni kr skte coz segmentation fault aa skta 
        q.pop();

        if(temp==NULL){
            //old level is completed so give a line break
            cout<<endl;
            if(!q.empty()){
                //q still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" "; 
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(node* root) {
    if (!root) return;

    queue<node*> q;
    stack<node*> s;

    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        // Push the node onto the stack
        s.push(temp);

        // Enqueue right child first, then left child
        // so that left is processed before right when popping from stack
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }

    // Now pop all items from stack and print
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

#include <vector>

// Function to print reverse level order traversal with each level on a new line
void reverseLevelOrderTraversalByLevel(node* root) {
    if (!root) return;

    queue<node*> q;
    vector<vector<int> > levels; // To store nodes level-wise

    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < n; ++i) {
            node* temp = q.front();
            q.pop();
            currentLevel.push_back(temp->data);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        levels.push_back(currentLevel);
    }

    // Print the levels from bottom to top
    for (int i = levels.size() - 1; i >= 0; --i) {
        for (int val : levels[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void inOrder(node* root){
    //base case
    if(root==NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(node* root){
    //base case
    if(root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    //base case
    if(root==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrderTraversal(node* &root){
    queue<node*> q;
    cout<<"Enter data for root: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){

    node* root = NULL;
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout<<"Printing the Tree in level order traversal by level..."<<endl;
    levelOrderTraversal(root);

    cout<<"Printing the Tree in reverse level order traversal..."<<endl;
    reverseLevelOrderTraversal(root);

    cout<<"Printing the Tree in reverse level order traversal by level..."<<endl;
    reverseLevelOrderTraversalByLevel(root);

    cout<<"Printing the Tree in in-order traversal..."<<endl;
    inOrder(root);

    cout<<endl;

    cout<<"Printing the Tree in pre-order traversal..."<<endl;
    preOrder(root);

    cout<<endl;

    cout<<"Printing the Tree in post-order traversal..."<<endl;
    postOrder(root);

    return 0;
}