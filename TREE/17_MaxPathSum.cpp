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
    int ans(TreeNode* node, int &sum){
        if(node==NULL)return 0;

        int lh=max(0,ans(node->left,sum));
        int rh=max(0,ans(node->right,sum));

        sum=max(sum,lh+rh+node->val);
        return node->val+max(lh,rh);
    }

    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        ans(root,sum);
        if(root->left == NULL){if(root->right == NULL){return root->val;}}
        return sum;
        
    }
};