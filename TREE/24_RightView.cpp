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

void rightview(Node* node,vector<int> &ans,int level){
    
    if(!node){return;}
    if(ans.size()==level){ans.push_back(node->data);}

    if(node->right){rightview(node->right,ans,level+1);}
    if(node->left){rightview(node->left,ans,level+1);}    
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
   
    //vertical order traversal
    cout<<"Right View: ";
    vector<int> ans;rightview(root,ans,0);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}