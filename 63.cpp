class Solution {
public:
    int getWays(int n, int m,vector<vector<int>>& dp,vector<vector<int>>& arr){
        if(n == 0 && m == 0 && arr[n][m] != 1){
            return 1;
        }
        if(n < 0 || m < 0 || arr[n][m] == 1){
            return 0;
        }

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        int top = getWays(n-1,m,dp,arr);
        int left = getWays(n, m-1, dp, arr);

        return dp[n][m] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));

        return getWays(n-1,m-1,dp,arr);
    }
};