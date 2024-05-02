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

bool solve(Node* left, Node* right){
    if(!left || !right){return left==right;}
    if(left->data!=right->data){return false;}

    return (solve(left->left,right->right)&&(solve(left->right,right->left)));
}
bool issym(Node* node){
    if(!node){return true;}
    bool ans=solve(node->left,node->right);
    return ans;      
}

int main(){
    //creating tree
    /*
                  1
               /    \
              2      3
            /  \    /  \
           4    5  6    7
              /        /  \
             8        9   10  
    */
    struct Node *root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right= new Node(5);
    root -> left -> right -> left= new Node(8);
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right= new Node(7);
    root -> right -> right -> left= new Node(9);
    root -> right -> right -> right= new Node(10);
   
    bool ans=issym(root);
    cout<<"Tree is : "<<(ans) ? "Symmetric" : "Not Symmetric";

    return 0;
}