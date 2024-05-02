class Solution {
private:
    void dfs(int n, int m, vector<vector<int>>& image, int row, int col,
             int newcol, int old, vector<vector<int>>& ans, int r[], int c[]) {

        ans[row][col] = newcol;
        for (int j = 0; j < 4; j++) {
            int nr = row + r[j];
            int nc = col + c[j];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                image[nr][nc] == old && ans[nr][nc] != newcol) {
                dfs(n, m, image, nr, nc, newcol, old, ans, r, c);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int old = image[sr][sc];
        vector<vector<int>> ans = image;
        int n = image.size();
        int m = image[0].size();
        int r[] = {0, +1, 0, -1};
        int c[] = {+1, 0, -1, 0};

        // if (old != color) {
            dfs(n, m, image, sr, sc, color, old, ans, r, c);
        // }

        return ans;
    }
};