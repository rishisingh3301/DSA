
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

bool pathtonode(Node* node, int B, vector<int>&ans){
    if(node==NULL)return false;
    ans.push_back(node->data);
    if(node->data==B){return true;}
    bool x,y;
    if(pathtonode(node->left,B,ans) || pathtonode(node->right,B,ans)){return true;}
    ans.pop_back();
    return false;
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
   
    //path to 8
    vector<int> ans;
    bool x=pathtonode(root,6,ans);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}