class Solution {
public:
    int getSum(vector<int>& nums, int ind, vector<int>& dp){
        dp[0] = nums[0];
        if(ind < 0){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int pick = nums[ind] + getSum(nums, ind-2, dp);
        int nPick = getSum(nums, ind - 1, dp);
        return dp[ind] = max(pick, nPick);
    }
    int rob(vector<int>& nums) {
        int ind = nums.size() - 1;
        vector<int> dp(nums.size(), -1);

        return getSum(nums, ind, dp);
    }
};

// tabulation

class Solution {
public:
    int getSum(vector<int>& nums, int ind, vector<int>& dp){
        dp[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int pick = nums[i];
            if(i > 1){
                pick += dp[i-2];
            }
            int nPick = dp[i-1];

            dp[i] = max(pick, nPick);
        }

        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int ind = nums.size() - 1;
        vector<int> dp(nums.size(), -1);

        return getSum(nums, ind, dp);
    }
};