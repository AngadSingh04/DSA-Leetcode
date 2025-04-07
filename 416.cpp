class Solution {
    public:
        bool solve(int idx, vector<int>& nums, int target, vector<vector<int>>& dp) {
    
            if (target == 0)
                return true;
    
    
            if (idx == 0) {
                return nums[0] == target;
            }
    
    
            if (dp[idx][target] != -1) {
                return dp[idx][target];
            }
    
            int not_take = solve(idx - 1, nums, target, dp);
    
    
            int take = false;
            if (nums[idx] <= target) {
                take = solve(idx - 1, nums, target - nums[idx], dp);
            }
    
    
            return dp[idx][target] = take || not_take;
        }
    
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            int n = nums.size();
    
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
            }
    
            if (sum % 2 == 1)
                return false;
    
            int target = sum / 2;
            vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    
            return solve(n - 1, nums, target, dp);
        }
    };