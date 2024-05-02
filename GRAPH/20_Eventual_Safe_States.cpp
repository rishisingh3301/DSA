class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& path){
        vis[node] = 1;
        path[node] = 1;

        for(auto adjnodes : graph[node]){
            if(vis[adjnodes] != 1){
                if(dfs(adjnodes, graph, vis, path)){return true;}
            }
            else if(path[adjnodes] == 1){
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        set<int> st;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, graph, vis, path);
            }
        }
        for(int i = 0; i < n; i++){
            if(path[i] == 0){
                st.insert(i);
            }
        }
        vector<int> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};