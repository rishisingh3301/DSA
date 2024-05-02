class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>q;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // int cnt=0;
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // cnt++;
            ans.push_back(node);
            for(auto adjnodes : adj[node]){
                indegree[adjnodes]--;
                if(indegree[adjnodes]==0){
                    q.push(adjnodes);
                }
            }
        }
        vector<int> fake;
        if(ans.size()!=n){return fake;}
        return ans;
    }
};