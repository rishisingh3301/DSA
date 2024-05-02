class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // int onecnt = 0;
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                // if (grid[i][j] == 1) {
                //     onecnt++;
                // }
            }
        }
        int delr[] = {0, 1, 0, -1};
        int delc[] = {1, 0, -1, 0};
        int t = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            t = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    vis[nr][nc] != 1 && grid[nr][nc]) {
                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 1;
                    // onecnt--;
                }
            }
        }
        // if(onecnt){return -1;}
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1 && vis[i][j]==0){
                    return -1;
                }
            }
        }
        return t;
    }
};