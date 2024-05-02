class Solution {
  public:
    void dfs(int V, vector<int> adj[], vector<int>&ans, int vis[],int starting){
        vis[starting]=1;
        ans.push_back(starting);
        for(auto it : adj[starting]){
            if(!vis[it]){
                dfs(V,adj,ans,vis,it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        vector<int> ans;
        int starting=0;
        dfs(V,adj,ans,vis,starting);
        return ans;
        
    }
};