class Solution
{
    private:
    void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>& adj){
        vis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,st,adj);
            }
        }
        
        st.push(node);
    }
    
    void revdfs(int node,vector<int>&vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                revdfs(it,vis,adj);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //make topo sort in stack
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
             if(!vis[i]){
                    dfs(i,vis,st,adj);
                }
        }
        
        //reverse the edges
        vector<int> revadj[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it : adj[i]){
                // i->it
                //it->i
                revadj[it].push_back(i);
            }
        }
        //do dfs in reversed edges style, and each dfs will add one scc
        int cnt=0;
        
        while(!st.empty()){
            int node=st.top();st.pop();
            if(!vis[node]){
                cnt++;
                revdfs(node,vis,revadj);
            }
        }
        return cnt;
    }
};