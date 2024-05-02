vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    //make adj list
    vector<int> adj[n];
    for(auto it : edges){
        int u=it[0];int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n,1e9);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();q.pop();
        for(auto it : adj[node]){
            if(dist[it]>dist[node]+1){
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]==1e9){
            dist[i]=-1;
        }
    }
    return dist;
}