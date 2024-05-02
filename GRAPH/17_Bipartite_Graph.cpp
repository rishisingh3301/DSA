class Solution {
private:
    bool bfs(int val,vector<vector<int>>& graph, vector<int>& vis){
        vis[val]=1;
        queue<pair<int,int>>q;
        q.push({val,1});
        while(!q.empty()){
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
            for(auto adj : graph[node]){
                if(vis[adj]==-1){
                    if(color==1){ vis[adj]=0;q.push({adj,0});}
                    else{vis[adj]=1;q.push({adj,1});}
                }
                else{
                    if(vis[adj]==color){return false;}
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!(bfs(i,graph,vis))){
                    return false;
                } 
            }
        }
        return true;
    }
};