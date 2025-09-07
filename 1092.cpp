class Solution {
public:
    string getCount(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>& dp){
        for(int i = 0; i <= ind1; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= ind2; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= ind1; i++){
            for(int j = 1; j <= ind2; j++){
                int match = 0;
                if(s1[i-1] == s2[j-1]){
                    match = 1 + dp[i-1][j-1];
                }
                int nmatch = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(match, nmatch);
            }
        }
        
        int len = dp[ind1][ind2];
        int count = ind1 + ind2 - len;
        int n1 = ind1;
        int n2 = ind2;
        string ans = "";
        ans.reserve(count);

        while(n1 > 0 && n2 > 0){
            if(s1[n1-1] == s2[n2-1]){
                ans += s1[n1-1];
                n1--;
                n2--;
            }else if(dp[n1-1][n2] > dp[n1][n2-1]){
                ans += s1[n1-1];
                n1--;
            }else{
                ans += s2[n2-1];
                n2--;
            }
        }

        while(n1 > 0){
            ans += s1[n1-1];
            n1--;
        }

        while(n2 > 0){
            ans += s2[n2-1];
            n2--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int ind1 = s1.size();
        int ind2 = s2.size();
        
        vector<vector<int>> dp(ind1+1, vector<int>(ind2+1, 0));
        return getCount(ind1, ind2, s1,s2,dp);
    }
};