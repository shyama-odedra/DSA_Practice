class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX = 0, startY = 0, emptyCount = 1;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 0) {
                    emptyCount++;
                }
            }
        }

        return dfs(grid, startX, startY, emptyCount);
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c, int remain) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == -1) {
            return 0;
        }

        if (grid[r][c] == 2) {
            return remain == 0 ? 1 : 0;
        }

        int temp = grid[r][c];
        grid[r][c] = -1; // Mark as visited

        int paths = dfs(grid, r + 1, c, remain - 1) +
                    dfs(grid, r - 1, c, remain - 1) +
                    dfs(grid, r, c + 1, remain - 1) +
                    dfs(grid, r, c - 1, remain - 1);

        grid[r][c] = temp; // Backtrack

        return paths;
    }
};