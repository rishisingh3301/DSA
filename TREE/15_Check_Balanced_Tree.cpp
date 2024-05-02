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

//brute force
int treeheight(Node* node){
    if(node == NULL)return 0;

    int lh=treeheight(node->left);
    int rh=treeheight(node->right);
    return max(lh,rh)+1;
}
bool isbalanced(Node* node){
    if(node == NULL)return true;
    
    int lh=treeheight(node->left);
    int rh=treeheight(node->right);
    if(abs(lh-rh)>1)return false;

    bool left=isbalanced(node->left);
    bool right=isbalanced(node->right);
    // if(!left || !right)return false;
    if(left==false || right==false)return false;
    return true;   
}

//optimal solution
bool ansoptimal(Node* node){
    int ans=isbalancedoptimal(node);
    if(ans==-1)return false;
    return ans;

}

int isbalancedoptimal(Node* node){
    if(node == NULL) return true;

    int lh=isbalancedoptimal(node->left);
    if(lh==-1)return -1;
    int rh=isbalancedoptimal(node->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;

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

    cout<<"Tree is : ";
    if(ansoptimal){cout<<"Balanced";}else{cout<<"Not balanced";}
    // cout<<isbalanced ? "Balanced" : "Not balanced";
    cout<<endl;


    return 0;
}