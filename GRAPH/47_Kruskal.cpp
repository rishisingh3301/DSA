#include<bits/stdc++.h>
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

int kruskalMST(int n, vector<vector<int>> &blah)
{
	vector<pair<int,pair<int,int>>> edges;
	for(auto it : blah){
		edges.push_back({it[2],{it[0],it[1]}});
	}
	DisjointSet ds(n);
	int mstwt=0;
	sort(edges.begin(),edges.end());
	for(auto it : edges){
		int wt=it.first;
		int u =it.second.first;
		int v=it.second.second;
		if(ds.findpar(u)!=ds.findpar(v)){
			mstwt+=wt;
			ds.unionbysize(u,v);
		}
	}
	return mstwt;
}