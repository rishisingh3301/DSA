
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
private:
    bool isvalid(int newr,int newc,int n){
        return newr>=0 && newc>=0 && newr<n && newc<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        //grouping all islands
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int newr = i+dr[k];
                        int newc = j+dc[k];
                        if(isvalid(newr,newc,n) && grid[newr][newc]==1){
                            int nodeno = i*n+j;
                            int adjnodeno = newr*n+newc;
                            ds.unionbysize(nodeno,adjnodeno);
                        }
                    }
                }
            }
        }
        //putting one over zero places and adding unique one who are attached with it
        //and 
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int>components;
                if(grid[i][j]==0){
                    for(int k=0;k<4;k++){
                        int newr = i+dr[k];
                        int newc = j+dc[k];
                        if(isvalid(newr,newc,n) && grid[newr][newc]==1){
                            int adjnodeno = newr*n+newc;
                            components.insert(ds.findpar(adjnodeno));
                        }
                    }
                }
                int sizeofisland = 1;
                for(auto it : components){
                    sizeofisland+=ds.size[it];
                }
                ans=max(ans,sizeofisland);
            }
        }
        //checking if no 0 in entire land then check for the biggest size of entire land
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findpar(i)]);
        }
        return ans;

    }
};