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

//by level order traversal
vector<vector<int>> zigzagtrav(Node* node){
    vector<vector<int>> ans;
    if(!node){return ans;}
    queue<Node*> q;
    q.push(node);
    bool flag=false;
    while(!q.empty()){
        int size=q.size();
        vector<int> row(size);
        for(int i=0; i<size; i++){
            Node* temp=q.front();
            q.pop();
            int index = (flag)? i : size - 1 - i;
            row[index]=temp->data;
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}

        }
        ans.push_back(row);
        flag=!flag;
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
   
    vector<vector<int>> zigzag=zigzagtrav(root);
    cout<<"Zigzag traversal is : ";
    for(auto it : zigzag){
        for(auto it1 : it){
            cout<<it1<<" ";
        }
    }
    


    return 0;
}