bool dfs(int node, vector<int> adj[], int vis[], int path[]){
	vis[node]=1;
	path[node]=1;

	for(auto adjnodes : adj[node]){
		//if adjacent node is not visited then do dfs over it
		if(vis[adjnodes]==0){
			if(dfs(adjnodes,adj,vis,path)){
				return true;
			}
		}
		//if adjacent node is visited
		else{
			if(path[adjnodes]==1){
				return true;
			}
		}
	}

	path[node]=0;
	return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<int> adj[v];
	for(int i=0;i<e;i++){
		adj[edges[i][0]].push_back(edges[i][1]);
	}
	int vis[v]={0};
	int path[v]={0};
	for(int i=0;i<v;i++){
		if(vis[i]!=1){
			if(dfs(i,adj,vis,path)){return true;}
		}
	}
	return false;
}
