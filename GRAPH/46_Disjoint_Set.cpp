#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    DisjointSet ds(7);
    ds.unionbysize(1, 2);
    ds.unionbysize(2, 3);
    ds.unionbysize(4, 5);
    ds.unionbysize(6, 7);
    ds.unionbysize(5, 6);
    // if 3 and 7 same or not
    if (ds.findpar(3) == ds.findpar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionbysize(3, 7);

    if (ds.findpar(3) == ds.findpar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    return 0;
}