class Solution {
public:
    int getCount(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[0] == 0){
                return amount/coins[0];
            }
            return INT_MAX;
        }

        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        int pick = INT_MAX;
        if(coins[ind] <= amount){
            int tmp = getCount(ind, coins, amount - coins[ind], dp);
            if(tmp != INT_MAX){
                pick = 1 + tmp;
            }
        }
        int npick = getCount(ind-1, coins, amount,dp);

        return dp[ind][amount] = min(pick,npick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // sort(coins.begin(),coins.end());
        int ind = n-1;

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans =  getCount(ind, coins, amount,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};