#include <queue>
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<int> adj[v];
	for(int i=0;i<e;i++){
		adj[edges[i][0]].push_back(edges[i][1]);
	}
	int indegree[v]={0};
	for(int i=0;i<v;i++){
		for(auto it : adj[i]){
			indegree[it]++;
		}
	}
	queue<int>q;
	for(int i=0;i<v;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	int cnt=0;
	while(!q.empty()){
		int node=q.front();q.pop();
		cnt++;
		for(auto it : adj[node]){
			indegree[it]--;
			if(indegree[it]==0){
				q.push(it);
			}
		}
	}
	if(cnt==v){
		return false;
	}
	return true;

}
