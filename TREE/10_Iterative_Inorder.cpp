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

vector<int> iterativeinordertrav(Node* node){
    //left root right
    stack<Node* > s;
    vector<int> ans;
    while(true){
        if(node != NULL){
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()){break;}
            node = s.top();
            s.pop();
            ans.push_back(node->data);
            node=node->right;
        }
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
    cout<<"Iterative Inorder traversal"<<endl;
    vector<int> ans=iterativeinordertrav(root);
    for(auto it: ans){cout<<it<<" ";}
    cout<<endl;


    return 0;
}