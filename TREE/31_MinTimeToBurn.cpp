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
    int burntree(TreeNode* root, TreeNode* node, map<TreeNode*,TreeNode*> &childparent){
        int ans=0;
        queue<TreeNode*> q;
        map<TreeNode*,bool> visited;
        visited[node]=true;
        q.push(node);
        while(!q.empty()){
            int size=q.size();
            int flag=0;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    visited[temp->left]=true;
                    q.push(temp->left);
                    flag=1;
                }
                if(temp->right && !visited[temp->right]){
                    visited[temp->right]=true;
                    q.push(temp->right);
                    flag=1;
                }
                if(!visited[childparent[temp]] && childparent[temp]){
                    visited[childparent[temp]]=true;
                    q.push(childparent[temp]);
                    flag=1;
                }
            }
            if(flag){ans++;}
        }
        return ans;
    }
    TreeNode* family(TreeNode* root,map<TreeNode*,TreeNode*> &childparent,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){   
                TreeNode* temp=q.front();
                if(temp->val==start){node=q.front();}
                q.pop();
                if(temp->left){q.push(temp->left);childparent[temp->left]=temp;}
                if(temp->right){q.push(temp->right);childparent[temp->right]=temp;}
            }
        }
        return node;

    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> childparent;
        TreeNode* node=family(root,childparent,start);
        int ans=burntree(root,node,childparent);
        return ans;

    }
};