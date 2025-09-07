class Solution {
public:
    int getCount(int n1, int n2, string& txt, string& pat, vector<vector<int>>& dp){

        for(int i = 0; i <= n1; i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j <= n2; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                int pick = 0;
                if(txt[i-1] == pat[j-1]){
                    pick = dp[i-1][j-1];
                }
                int npick = dp[i-1][j];
                dp[i][j] = (long long)pick + (long long)npick;
            }
        }

        return dp[n1][n2];
    }
    int numDistinct(string txt, string pat) {
        int n1 = txt.size();
        int n2 = pat.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        
        return getCount(n1, n2, txt, pat, dp);
    }
};