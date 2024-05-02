class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int r[]={1,0,-1,0};
        int c[]={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if((row == n-1) && (col == m-1)){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nr=row+r[i];
                int nc=col+c[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newdiff = max(abs(heights[nr][nc]-heights[row][col]),diff);
                    if(newdiff < dist[nr][nc]){
                        dist[nr][nc]=newdiff;
                        pq.push({newdiff,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};