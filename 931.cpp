class Solution {
public:
    int getSum(int size, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int n = matrix.size();
        int m = matrix[0].size();

        for(int j = 0; j < m; j++){
            dp[size-1][j] = matrix[size-1][j];
        }
        for(int i = size-2; i >= 0; i--){
            for(int j = 0; j < m; j++){
                int dl = 1e9;
                int dr = 1e9;
                int down  = matrix[i][j] + dp[i+1][j];
                if(j-1 >= 0){
                    dl = matrix[i][j] + dp[i+1][j-1];
                }
                if(j+1 < m){
                    dr = matrix[i][j] + dp[i+1][j+1];
                }

                dp[i][j] = min(down, min(dl,dr));
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j < m; j++){
            mini = min(mini, dp[0][j]);
        }
        return mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return getSum(n,matrix,dp);
    }
};