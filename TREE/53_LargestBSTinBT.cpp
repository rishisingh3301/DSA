/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class info{
    public:
    bool isBST;
    int maxi;
    int mini;
    int size;
};
class Solution{
    public:
    info solve(Node* node){
        if(!node){
            return {true,INT_MIN,INT_MAX,0};
        }
        info left=solve(node->left);
        info right=solve(node->right);
        
        info x;
        
        if(left.isBST && right.isBST && node->data>left.maxi && node->data<right.mini){
            x.isBST=true;
            x.size=left.size + right.size + 1;
            x.maxi=max(node->data,right.maxi);
            x.mini=min(node->data,left.mini);
        }
        else{
            x.isBST=false;
            x.size=max(left.size,right.size);
            x.maxi=INT_MIN;
            x.mini=INT_MAX;            
        }
        
        return x;
    }
    int largestBst(Node *root)
    {
        return solve(root).size;
    }
};