class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        vis[i][j] = 1;
                        q.push({i, j});

                    } else {
                        cnt++;
                    }
                }
            }
        }

        int r[] = {0, 1, 0, -1};
        int c[] = {1, 0, -1, 0};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + r[i];
                int nc = col + c[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    vis[nr][nc] != 1 && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                    cnt--;
                }
            }
        }
        return cnt;
    }
};