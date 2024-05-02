/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool check(TreeNode* node, long long minval, long long maxval){
        if(node==NULL)return true;      
        if(node->val >= maxval || node->val <= minval){return false;}
        return (check(node->left,minval,node->val))&&(check(node->right,node->val,maxval));
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;        
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};