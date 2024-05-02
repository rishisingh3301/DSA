// User function Template for C++

class DisjointSet
{
public:
    vector<int> parent, rank, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findpar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }

    void unionbyrank(int u, int v)
    {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv)
        {
            return;
        }
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionbysize(int u, int v)
    {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv)
        {
            return;
        }
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        /*
        make vis array
        makedisjoint set
        go to each query
        if index at query is already visitedthe npush already ans and continue
        if it's not visited then makrit visited andincrease number of island
        now move in all four direction with valid boundry check
        and when it's in within boundry check if that index is land or not
        if it's land and has different ultimate parent 
        then decrease the count and merge that with this island
        merging can happen by disjoint union of these two indexes
        for merging and all we need to make index into numbers 
        
        */
        DisjointSet ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans;
        int cnt=0;
        for(auto it : operators){
            int row=it[0];int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int dr[]={0,1,0,-1};
            int dc[]={1,0,-1,0};
            for(int ind=0;ind<4;ind++){
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    if(vis[newr][newc]==1){
                        int node = row*m + col;
                        int adjnode = newr*m + newc;
                        if(ds.findpar(node)!=ds.findpar(adjnode)){
                            cnt--;
                            ds.unionbysize(node,adjnode);
                        }
                        
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
    }
};