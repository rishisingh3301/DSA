
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

vector<vector<int>> verticalordtrav(Node* node){
    /*
    map  -2 -1 0 1 2
    vertical,level
    
    */
   vector<vector<int>> ans;
   if(!node){return ans;}
   map<int,map<int,multiset<int>>> m;
   queue<pair<Node*,pair<int,int>>> q;
   q.push({node,{0,0}});
   while(!q.empty()){
    auto n = q.front();
    q.pop();
    int x=n.second.first;
    int y=n.second.second;
    m[x][y].insert(n.first->data);
    if(n.first->left){
        q.push({n.first->left,{x-1,y+1}});
    }
    if(n.first->right){
        q.push({n.first->right,{x+1,y+1}});
    }
    }
    for(auto p : m){
        vector<int> temp;
        for(auto q : p.second){
            temp.insert(temp.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(temp);
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
    cout<<"Vertical Order Traversal: ";
    vector<vector<int>> ans=verticalordtrav(root);
    for(auto it : ans){
        for(auto it1 : it){
            cout<<it1<<" ";
        }
    }
    return 0;
}