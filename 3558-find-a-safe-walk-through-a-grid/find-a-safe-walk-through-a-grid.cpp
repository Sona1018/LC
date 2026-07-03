class Solution {
public:

    bool dfs(int i, int j, int health,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,vector<vector<bool>>& visited) {

        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if(visited[i][j])
            return false;

        if(grid[i][j] == 1)
            health--;

        if(health < 1)
            return false;

        if(i == m - 1 && j == n - 1)
            return true;

        if(dp[i][j][health] != -1)
            return dp[i][j][health];

        visited[i][j] = true;

        bool ans =
            dfs(i + 1, j, health, grid, dp, visited) ||
            dfs(i - 1, j, health, grid, dp, visited) ||
            dfs(i, j + 1, health, grid, dp, visited) ||
            dfs(i, j - 1, health, grid, dp, visited);

        visited[i][j] = false;

        return dp[i][j][health] = ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(0, 0, health, grid, dp, visited);
    }
};