class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=r+i;
                    int ncol=c+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};