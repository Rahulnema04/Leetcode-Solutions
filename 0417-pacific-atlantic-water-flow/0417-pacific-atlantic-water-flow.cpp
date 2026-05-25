class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, int r, int c,
             vector<vector<bool>>& vis) {

        vis[r][c] = true;

        for (auto d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(heights, nr, nc, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            dfs(heights, i, 0, pac);
            dfs(heights, i, m - 1, atl);
        }

        for (int j = 0; j < m; j++) {
            dfs(heights, 0, j, pac);
            dfs(heights, n - 1, j, atl);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};