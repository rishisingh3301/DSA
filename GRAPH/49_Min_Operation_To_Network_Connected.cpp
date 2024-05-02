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
    int makeConnected(int n, vector<vector<int>>& connections) {
        //find number of separate componets
        //find extra edges
        //minimum connections reqd to make everyone connected = no_Of_Separate_Components-1
        //if extra edges > = noofseparatecomp then ans = no_Of_Separate_Components-1
        //else -1
        DisjointSet ds(n);
        int extraedge=0;
        for(auto it : connections){
            int u=it[0];
            int v=it[1];
            if(ds.findpar(u)==ds.findpar(v)){extraedge++;}
            else{
                ds.unionbyrank(u,v);
            }
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.findpar(i)==i)components++;
        }
        int ans=components-1;
        if(extraedge >= ans)return ans;
        return -1;
    }
};