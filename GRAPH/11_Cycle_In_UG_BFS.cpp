#include<queue>
bool detect(vector<int> adj[], int src, int vis[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int source=q.front().second;
        q.pop();
        for(int i=0; i<adj[node].size();i++){
            if(vis[adj[node][i]]!=1){
                q.push({adj[node][i],node});
                vis[adj[node][i]]=1;
            }
            else if(adj[node][i]!=source){
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    // for(auto edge : edges){
    //     adj[edge[0]].push_back(edge[1]);
    // }
    for(int i=0;i<m;i++){
        int firstnode=edges[i][0];
        int secondnode=edges[i][1];
        adj[firstnode].push_back(secondnode);
        adj[secondnode].push_back(firstnode);
    }
    int vis[n+1]={0};
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(detect(adj,i,vis)){
                return "Yes";
            }
        }
    }
    return "No";

}
