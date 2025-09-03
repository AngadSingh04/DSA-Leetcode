class Solution {
public:
    int getSum(int i, int j1, int j2,vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>>& dp){
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m){
            return -1e9;
        }
        if(i == n-1){
            if(j1 == j2){
                return grid[i][j1];
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }

        int maxi = 0;
        for(int k = -1; k <= 1; k++){
            for(int l = -1; l <= 1; l++){
                if(j1 == j2){
                    maxi = max(maxi, grid[i][j1]+getSum(i+1, j1 + k, j2 + l, grid, n, m, dp));
                }else{
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + getSum(i+1, j1+k, j2+l, grid, n , m, dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;
        int j1 = 0;
        int j2 = m-1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));

        return getSum(i,j1,j2,grid,n,m,dp);
    }
};