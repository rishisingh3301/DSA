#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;
    Node(int val){
        data = val;
        left = right = nullptr;
    } 
};

Node* searchBST(Node* node, int target){
   while(node!=NULL && node->data!=target){
    node = node->data<target ? node->right : node->left;
   }
   return node;
}

int main(){
    //creating tree
    /*
                 20
               /    \
              15      28
            /  \     /  \
           14   17  26  37
              /        /  \
             16        29   40  
    */
    struct Node *root = new Node(20);
    root -> left = new Node(15);
    root -> left -> left = new Node(14);
    root -> left -> right= new Node(17);
    root -> left -> right -> left= new Node(16);
    root -> right = new Node(28);
    root -> right -> left = new Node(26);
    root -> right -> right= new Node(37);
    root -> right -> right -> left= new Node(29);
    root -> right -> right -> right= new Node(40);
   
    //vertical order traversal
    Node* search=searchBST(root,29);
    if(search){cout<<"FOUND";}
    else{cout<<"NOT FOUND";}
    return 0;
}