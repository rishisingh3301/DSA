class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    matrix[i][j] = 0;
            }
        }
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }

        // floyd warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // if (matrix[i][k] != 1e9 && matrix[k][j]!=1e9){
                            matrix[i][j] =
                                min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                        // }
                }
            }
        }
        int city;
        int maxcity = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt=0;
            for (int j = 0; j < n; j++) {
                if(matrix[i][j]<=dt)cnt++;
            }
            if(cnt<=maxcity){
                city=i;
                maxcity=cnt;
            }
        }
        return city;
    }
};