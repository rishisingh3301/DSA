
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
    int removeStones(vector<vector<int>>& stones) {
        //obtaining maxrow and maxcol so that when we will assign node values we 
        //can assign disjoint set size
        int maxrow=-1;
        int maxcol=-1;
        for(auto it : stones){
            int row = it[0];
            int col= it[1];
            maxrow=max(maxrow,row);
            maxcol=max(maxcol,col);
        }
        //making disjoint set for every row and col on which stones are found
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>mp;
        for(auto it : stones){
            int row = it[0];
            int col = maxrow + 1 + it[1];
            ds.unionbysize(row,col);
            mp[row]=1;
            mp[col]=1;
        }
        //on every one component we can remove all stones excet one
        //therefore numberof stones removed will be total stones - no of components
        //now we have to calculate number of components
        //in map we are storing all row and col node number
        //and then they are used to find number of component
        int cnt=0;
        int n=stones.size();
        for(auto it : mp){
            int index = it.first;
            if(ds.findpar(index)==index)cnt++;
        }
        return n-cnt;

    }
};