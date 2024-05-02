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

void alltrav(Node* node, vector<int> &pre,  vector<int> &in,  vector<int> &post){
    //left right root
    stack<pair<Node*,int>> st;
    if(node == NULL) return;
    st.push({node,1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != NULL){
                st.push({it.first->left,1});
            }
        }
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != NULL){
                st.push({it.first->right,1});
            }
        }
        else if(it.second == 3){
            post.push_back(it.first->data);
        }
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
    vector<int> pre,in,post;
    alltrav(root,pre,in,post);
    cout<<"Pre order"<<endl;
    for(auto it : pre){cout<<it<<" ";}cout<<endl;
    cout<<"In order"<<endl;
    for(auto it : in){cout<<it<<" ";}cout<<endl;
    cout<<"Post order"<<endl;
    for(auto it : post){cout<<it<<" ";}cout<<endl;

    return 0;
} 