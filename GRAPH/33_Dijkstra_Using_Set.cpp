class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        /*
        declare set<pair<dist,node>>
        distance array
        */
        vector<int> dist(V,1e9);
        dist[S]=0;
        set<pair<int,int>>st;
        st.insert({0,S});
        while(!st.empty()){
            auto pr = *(st.begin());
            int distance = pr.first;
            int u = pr.second;
            // st.erase(pr);
            st.erase(st.begin());
            for(auto it : adj[u]){
                int v = it[0];
                int wt = it[1];
                if(dist[v]>distance+wt){
                // st.erase({dist[v],v});
                    // dist[v]=distance+wt;
                    dist[v]=dist[u]+wt;
                st.insert({dist[v],v});
                }
            }
        }
        return dist;
        
    }
};