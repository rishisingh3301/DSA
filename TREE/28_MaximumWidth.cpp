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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        long long width=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long size=q.size();
            long long minind=q.front().second;
            long long first,last;
            for(long long i=0;i<size;i++){
                long long index=q.front().second-minind;
                if(i==0){first=index;}
                if(i==size-1){last=index;}
                TreeNode* node=q.front().first;
                q.pop();
                if(node->left){q.push({node->left,2*index+1});}
                if(node->right){q.push({node->right,2*index+2});}
            }
            width=max(width,last-first+1);
        }
        return width;        
    }
};