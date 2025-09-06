class Solution {
public:
    int getMax(int ind1, int ind2, string text1, string text2, vector<vector<int>>& dp){
        for(int i = 0; i <= ind1; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= ind2; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= ind1; i++){
            for(int j = 1; j <= ind2; j++){
                int match = 0;
                if(text1[i-1] == text2[j-1]){
                    match = 1 + dp[i-1][j-1];
                }
                int nmatch = max(dp[i-1][j], dp[i][j-1]);

                dp[i][j] = max(match,nmatch);
            }
        }
        return dp[ind1][ind2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        int ind1 = n1;
        int ind2 = n2;

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        return getMax(ind1, ind2, text1, text2, dp);
    }
};