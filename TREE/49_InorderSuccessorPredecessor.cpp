/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
int pred(TreeNode*root,int key) {//floor
    int ans=-1;
    while(root){
        if(key > root->data){
            ans=root->data;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return ans;
}
int succ(TreeNode*root,int key) {//ceil
    int ans=-1;
    while(root){
        if(root->data > key){
            ans=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ans;
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
  return {pred(root,key),succ(root,key)};
}