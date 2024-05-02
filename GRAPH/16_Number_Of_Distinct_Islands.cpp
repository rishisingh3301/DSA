// User function Template for C++

class Solution {
  private:
    int bfs(int row,int col, vector<vector<int>>& grid, 
             vector<vector<int>>& vis,set<vector<pair<int,int>>>& st){
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> ans;
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        ans.push_back({row-row,col-col});
        int r[]={1,0,-1,0};
        int c[]={0,1,0,-1};
        while(!q.empty()){
            int xrow=q.front().first;
            int xcol=q.front().second;
            q.pop();
           
            for(int i=0;i<4;i++){
                int nr=xrow+r[i];
                int nc=xcol+c[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m
                    && vis[nr][nc]!=1 && grid[nr][nc]==1){
                        q.push({nr,nc});
                        ans.push_back({nr-row,nc-col});
                        vis[nr][nc]=1;
                    }
                }
        }
        st.insert(ans);
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=1){
                    bfs(i,j,grid,vis,st);
                }
            }
        }
        return st.size();
    }
};