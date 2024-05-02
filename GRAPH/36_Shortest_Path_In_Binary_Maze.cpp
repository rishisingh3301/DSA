class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1){return -1;}
        if(n==1){return 1;}
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it = q.front();q.pop();
            int step = it.first;int r = it.second.first;int c = it.second.second;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr = r+i;
                    int nc = c+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n &&
                        grid[nr][nc]==0 && (step+1 < dist[nr][nc])){
                            dist[nr][nc]=step+1;
                            if(nr == n-1 && nc == n-1){
                                return step+1;
                            }
                            q.push({step+1,{nr,nc}});
                        }
                }
            }
        }
        return -1;
    }
};