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

vector<int> iterativepostordertrav(Node* node){
    //left right root
    stack<Node*> st1,st2;
    Node* root;
    vector<int> ans;
    st1.push(node);
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
        if(st2.top()->left!=NULL){
            st1.push(st2.top()->left);
        }
        if(st2.top()->right!=NULL){
            st1.push(st2.top()->right);
        }
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
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
    cout<<"Iterative Postorder traversal"<<endl;
    vector<int> ans=iterativepostordertrav(root);
    for(auto it: ans){cout<<it<<" ";}
    cout<<endl;


    return 0;
}