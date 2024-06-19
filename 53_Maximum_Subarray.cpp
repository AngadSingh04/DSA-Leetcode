class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxN = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            maxN = max(nums[i], maxN + nums[i]);
            if(maxN > ans){
                ans = maxN;
            }
        }
        return ans;
    }
};
