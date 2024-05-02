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


int diameter(Node* node, int &diam){
    if(node==NULL)return 0;

    int lh=diameter(node->left,diam);
    int rh=diameter(node->right,diam);

    diam=max(diam,lh+rh);

    return 1+max(lh,rh);
}


int main(){
    //creating tree
    /*
                1
        2              3
    4       5      6       7
          8              9   10  
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
   
    int diam=0;int ans=diameter(root,diam);
    cout<<"Diameter of Tree is is : "<<diam;
    


    return 0;
}