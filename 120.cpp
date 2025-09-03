class Solution {
public:
    int getSum(int i, int j, int size, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        for(int k = 0; k <= size-1; k++){
            dp[size-1][k] = triangle[size-1][k];
        }

        for(int k = size-2; k >= 0; k--){
            for(int l = 0; l <= k; l++){
                int top = triangle[k][l] + dp[k+1][l];
                int diag = triangle[k][l] + dp[k+1][l+1];

                dp[k][l] = min(top,diag);
            }
        }

        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<vector<int>> dp(size, vector<int>(size,-1));
        return getSum(0,0,size, triangle, dp);
    }
};