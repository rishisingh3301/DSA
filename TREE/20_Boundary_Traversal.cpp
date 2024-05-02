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

//boundary traversal
bool isLeaf(Node* node){
    if(node->left || node->right)return false;
    return true;
}

void addLeftBoundary(Node* node,vector<int> &res){
    Node* cur = node->left;
    while(cur){
        
        if(!isLeaf(cur)){res.push_back(cur->data);}
        if(cur->left){cur=cur->left;}
        else{cur=cur->right;}
    }
}

void addLeaves(Node* node,vector<int> &res){
    if(isLeaf(node)){
    res.push_back(node->data);
    return;}
    if(node->left) addLeaves(node->left,res);
    if(node->right) addLeaves(node->right,res);
    
}

void addrightBoundary(Node* node,vector<int> &res){
    Node* cur=node->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)){temp.push_back(cur->data);}
        if(cur->right){cur=cur->right;}
        else{cur=cur->left;}
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }

}

void boundarytrav(Node* node,vector<int> &res){
    if(!node)return ;
    if(!isLeaf(node)){res.push_back(node->data);}
    
    //add left boundary
    addLeftBoundary(node,res);
    //add leaves
    addLeaves(node,res);
    //add right boundary
    addrightBoundary(node,res);
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
   
    //boudanry traversal
    cout<<"Boundary Traversal: ";
    vector<int> res;
    boundarytrav(root,res);
    for(auto it : res){
        cout<<it<<" ";
    }

    return 0;
}