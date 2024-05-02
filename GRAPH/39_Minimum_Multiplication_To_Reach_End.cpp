#include<bits/stdc++.h>
int minimumOperations(int n, int start, int end, vector<int> &a)
{
    int mod=1000;
    //{node,steps}
    queue<pair<int,int>>q;
    vector<int> dist(mod,1e9);
    q.push({start,0});
    dist[start%mod]=0;
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        if (node == end) {
          return steps;
        }
        q.pop();
        for(auto it : a){
            int number = (it * node)%mod;
            if(steps+1 < dist[number]){
                dist[number]=steps+1;
                q.push({number,steps+1});

            }
        }
    }
    return -1;

}