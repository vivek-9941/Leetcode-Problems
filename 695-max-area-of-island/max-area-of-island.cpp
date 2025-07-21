class Solution {
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c, int& area) {
        int m = grid.size(), n = grid[0].size();
        vis[r][c] = 1;
        area++;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(grid, vis, nr, nc, area);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int area = 0;
                    dfs(grid, vis, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
