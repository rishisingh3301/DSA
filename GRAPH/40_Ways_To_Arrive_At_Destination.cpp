class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long  mod = 1000000007;
        vector<pair<long long,long long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,long long>,
        vector<pair<long long,long long>>,
        greater<pair<long long,long long>>
        > pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long dis = pq.top().first;
            long long u = pq.top().second;
            pq.pop();
            for(auto it : adj[u]){
                long long v = it.first;
                long long wt = it.second;
                if(dis+wt == dist[v]){
                    ways[v]=(ways[v]+ways[u])%mod;
                }
                else if(dis+wt < dist[v]){
                    ways[v]=ways[u]%mod;
                    dist[v]=dis+wt;
                    pq.push({dis+wt,v});
                }
            }
        }
        return ways[n-1]%mod;
    }
};