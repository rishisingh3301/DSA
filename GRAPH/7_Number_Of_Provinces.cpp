void bfs(int node,vector<vector<int>>& roads, int n,vector<int> &vis){
    vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(roads[v][i]==1 && vis[i]!=1){
                vis[i]=1;
                q.push(i);
            }
        }

    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    int cnt=0;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            cnt++;
            bfs(i,roads,n,vis);
        }
    }
    return cnt;
}