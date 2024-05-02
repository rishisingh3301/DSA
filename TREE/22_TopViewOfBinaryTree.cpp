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

vector<int> topview(Node* node){
    /*
    map - line,value //bcz we are sorting on the basis of line
    queue - node, line of that node
    */
   vector<int> ans;
   if(!node){return ans;}
   map<int,int> m;
   queue<pair<Node*,int>> q;
   q.push({node,0});
   while(!q.empty()){
    auto pr = q.front();
    q.pop();
    auto n = pr.first;
    auto line = pr.second;
    //insert new value if didn't find it already
    if(m.find(line) == m.end()){m.insert({line,n->data});}
    if(n->left){q.push({n->left,line-1});}
    if(n->right){q.push({n->right,line+1});}
   }
   for(auto it : m){
    ans.push_back(it.second);
   }
   return ans;
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
   
    //vertical order traversal
    cout<<"Top View: ";
    vector<int> ans=topview(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}