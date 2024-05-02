/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fillparentchild( map<TreeNode*,TreeNode*> &parentchild, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();q.pop();
            if(temp->left){parentchild[temp->left]=temp;q.push(temp->left);}
            if(temp->right){parentchild[temp->right]=temp;q.push(temp->right);}
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parentchild;
        fillparentchild(parentchild,root);

        queue<TreeNode*> q;
        q.push(target);
        int cnt=0;
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        while(!q.empty()){
            if(cnt==k)break;
            cnt++;
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(parentchild[temp] && !visited[parentchild[temp]]){
                    q.push(parentchild[temp]);
                    visited[parentchild[temp]]=true;
                }
            }
        }
        vector<int> ans;
        int len=q.size();
        for(int i=0;i<len;i++){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};