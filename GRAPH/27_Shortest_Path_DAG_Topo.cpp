#include<bits/stdc++.h>
vector<int> toposort(int n,vector<pair<int,int>>adj[]){
    int indegree[n]={0};
    for(int i=0;i<n;i++){
        vector<pair<int,int>>u=adj[i];
        for(auto pr : u){
            int v=pr.first;
            indegree[v]++;
        }
    }
    vector<int>ans;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            int v=it.first;
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    return ans;

}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    //make adj list
    //do topo sort 
    //make distance array
    //distance algo and update distance
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    
    vector<int> topo=toposort(n,adj);
    vector<int>dis(n,1e9);
    dis[0]=0;
    for(int i=0;i<topo.size();i++){
        int u=topo[i];
        for(auto pr : adj[topo[i]]){
            int v=pr.first;
            int wt=pr.second;
            dis[v]=min(dis[v],dis[u]+wt);
        }
    }
    for(int i=0;i<n;i++){
        if(dis[i]==1e9){
            dis[i]=-1;
        }
    }
    return dis;
}
