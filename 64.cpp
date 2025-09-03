class Solution {
public:
    int getSum(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                int top = INT_MAX;
                int left = INT_MAX;
                if(i == 0 && j == 0){
                    dp[0][0] = grid[0][0];
                }else{
                    if(i > 0){
                        top = grid[i][j] + dp[i-1][j];
                    }
                    if(j > 0){
                        left = grid[i][j] + dp[i][j-1];
                    }
                    dp[i][j] = min(top,left);
                }
            }
        }
        return dp[n][m];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));

        return getSum(n-1,m-1,grid,dp);
    }
};