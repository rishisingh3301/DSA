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

void inordertrav(Node* node){
    if(node == nullptr){return;}
    inordertrav(node->left);
    cout<<node->data<<" ";
    inordertrav(node->right);
}

void length(Node* node, int &len){
    if(node==NULL)return;
    length(node->left,len);
    len++;
    length(node->right,len);
}

void kthlargest(Node* node,int k, int& ans,int& cnt, int&len){
    if(node==NULL)return;
    kthlargest(node->left,k,ans,cnt,len);
    cnt++;
    if(cnt==len-k+1){ans=node->data;return;}
    kthlargest(node->right,k,ans,cnt,len);    
}

void kthsmallest(Node* node,int k, int& ans,int& cnt){
    if(node==NULL)return;
    kthsmallest(node->left,k,ans,cnt);
    cnt++;
    if(cnt==k){ans=node->data;return;}
    kthsmallest(node->right,k,ans,cnt);
}



int main(){
    //creating tree
    /*
                 20
               /    \
              15      28
            /  \     /  \
           14   17  26  37
              /        /  \
             16        29   40  
    */
    struct Node *root = new Node(20);
    root -> left = new Node(15);
    root -> left -> left = new Node(14);
    root -> left -> right= new Node(17);
    root -> left -> right -> left= new Node(16);
    root -> right = new Node(28);
    root -> right -> left = new Node(26);
    root -> right -> right= new Node(37);
    root -> right -> right -> left= new Node(29);
    root -> right -> right -> right= new Node(40);

    cout<<"Tree is: ";inordertrav(root);
    int k;cin>>k;
    int ans;int cnt=0;
    int len=0;length(root,len);
    kthsmallest(root,len-k+1,ans,cnt);
    // kthlargest(root,k,ans,cnt,len);
    cout<<endl<<k<<"th Largest element "<<ans;
   
   
    return 0;
}