/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* node,bool left){
        int h=0;
        while(node){
            h++;
            if(left){node=node->left;}
            else{node=node->right;} 
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root){return 0;}
        int lh = height(root,true);
        int rh = height(root,false);
        if(lh==rh){return (1<<lh)-1;}
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};