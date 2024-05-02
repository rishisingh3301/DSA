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

vector<int> iterativepreordertrav(Node* node){
    vector<int> ans;
    if(node == nullptr){return ans;}

    stack<Node*> s;
    s.push(node);
    while(!s.empty()){
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if(temp->right!=NULL){s.push(temp->right);}
        if(temp->left!=NULL){s.push(temp->left);}
    }
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
    cout<<"Iterative Preorder traversal"<<endl;
    vector<int> ans=iterativepreordertrav(root);
    for(auto it : ans){cout<<it<<" ";}
    cout<<endl;


    return 0;
}