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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    void inorder(TreeNode* node){
        if(node==NULL)return;
        inorder(node->left);
        if(node->val < prev->val){
            if(first==NULL){
                first=prev;
                middle=node;
            }
            else{
                last=node;
            }
        }
        prev=node;
        inorder(node->right);
    }
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(last){swap(first->val,last->val);}
        else{swap(first->val,middle->val);}
    }
};