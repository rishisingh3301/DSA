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

vector<int> levelordertrav(Node *root){
    vector<int> ans;
    if(root==NULL){return ans;}
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp;
        temp=q.front();
        q.pop();
        if(temp->left!=NULL){q.push(temp->left);}
        if(temp->right!=NULL){q.push(temp->right);}
        ans.push_back(temp->data);
    }
    return ans;
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

    //printing root
    cout<<"Level order traversal"<<endl;
    vector<int> ans=levelordertrav(root);
    for(auto it : ans){cout<<it<<" ";}
    cout<<endl;


    return 0;
}