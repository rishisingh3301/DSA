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
    TreeNode* maketree(vector<int>& preorder, int prestart, int preend,
                       vector<int>& inorder, int instart, int inend,
                       map<int, int>& inordmap) {
        if (prestart > preend || instart > inend) {
            return NULL;
        }
        int inroot = inordmap[preorder[prestart]];
        int numleft = inroot - instart;
        TreeNode* root = new TreeNode(preorder[prestart]);
        root->left = maketree(preorder, prestart + 1, prestart + numleft,
                              inorder, instart, inroot - 1, inordmap);
        root->right = maketree(preorder, prestart + numleft + 1, preend,
                               inorder, inroot + 1, inend, inordmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // making hash of inorder array
        map<int, int> inordmap;
        for (int i = 0; i < inorder.size(); i++) {
            inordmap[inorder[i]] = i;
        }

        TreeNode* root = maketree(preorder, 0, preorder.size() - 1, inorder, 0,
                                  inorder.size() - 1, inordmap);
        return root;
    }
};