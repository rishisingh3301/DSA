class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair< pair<int,int>,int> > q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int r[]={0,1,0,-1};
        int c[]={1,0,-1,0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            ans[row][col]=time;
            for(int i=0;i<4;i++){
                int nr=row+r[i];
                int nc=col+c[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m &&
                !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},time+1});
                }
            }
        }
        return ans;
    }
};