class Solution {
public:
    int getCount(int ind, int n, string s, vector<int>& dp){
        if(ind == n){
            return 1;
        }
        if(s[ind] == '0'){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int first = getCount(ind+1,n, s, dp);
        int second = 0;
        if(ind+1 < n){
            if(s[ind] == '1' || s[ind] == '2' && s[ind+1] <= '6'){
                second = getCount(ind+2, n, s, dp);
            }
        }

        return dp[ind] = first+second;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);

        return getCount(0, n, s, dp);
    }
};