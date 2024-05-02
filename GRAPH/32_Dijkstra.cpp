#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    int n=vertices;
    int m=edges;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u=edge[i][0];
        int v=edge[i][1];
        int wt=edge[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int>dist(n,INT_MAX);
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    while(!pq.empty()){
        int step=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dist[v]>wt+dist[node]){
                dist[v]=wt+dist[node];
                pq.push({dist[v],v});
            }
        }
    }
    return dist;

}