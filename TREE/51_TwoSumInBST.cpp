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
class BSTiterator{
    private:
    stack<TreeNode*> st;
    bool reverse=true;
    void pushstack(TreeNode* node, bool reverse){
        while(node){
            st.push(node);
            if(reverse){node=node->right;}//before
            else{node=node->left;}//next
        }
    }
    
    public:
    BSTiterator(TreeNode* root, bool isreverse){
        reverse=isreverse;
        pushstack(root,reverse);
    }
    int next(){
        TreeNode* temp=st.top();st.pop();
        if(reverse){pushstack(temp->left,reverse);}//before
        else{pushstack(temp->right,reverse);}//next
        return temp->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root){return false;}
        BSTiterator l(root,false);//left
        BSTiterator r(root,true);//right

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k){return true;}
            else if(i+j>k){
                j=r.next();
            }
            else{
                i=l.next();
            }
        }
        return false;
    }
};