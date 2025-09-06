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

// tabulation

class Solution {
public:
    int getCount(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        for(int i = 0; i <= ind; i++){
            dp[i][0] = 0;
        }
        for(int i = 1; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }else{
                dp[0][i] = INT_MAX;
            }
        }
        for(int i = 1; i <= ind; i++){
            for(int j = 1; j <= amount; j++){
                int pick = INT_MAX;
                if(coins[i] <= j){
                    int tmp = dp[i][j - coins[i]];
                    if(tmp != INT_MAX){
                        pick = 1 + tmp;
                    }
                }
                int npick = dp[i-1][j];

                dp[i][j] = min(pick,npick);
            }
        }
        return dp[ind][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // sort(coins.begin(),coins.end());
        int ind = n-1;
        if(amount == 0){
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        int ans =  getCount(ind, coins, amount,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};