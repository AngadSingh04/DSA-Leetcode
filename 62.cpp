class Solution {
public:
    int getWays(int m, int n, vector<vector<int>>& dp){
        // if(m == 0 && n == 0){
        //     return 1;
        // }
        dp[0][0] = 1;
        if(m < 0 || n < 0){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int top = getWays(m-1,n,dp);
        int left = getWays(m,n-1,dp);

        return dp[m][n] = top+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return getWays(m-1,n-1, dp);
    }
};

// tabulation
class Solution {
public:
    int getWays(int m, int n, vector<vector<int>>& dp){

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int top = 0;
                int left = 0;
                if(i == 0 && j == 0){
                    dp[0][0] = 1;
                }else{
                    if(i > 0){
                        top = dp[i-1][j];
                    }
                    if(j > 0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = top + left;
                }
            }
        }

        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return getWays(m,n, dp);
    }
};