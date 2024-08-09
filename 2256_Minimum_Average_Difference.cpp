class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        for(int num: nums){
            sum+=num;
        }
        long long left = 0;
        long long right = sum;
        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            left += nums[i];
            right -= nums[i];
            int lp = i+1;
            int rp = nums.size()-i-1;
            int leftAvg = left/lp;
            int rightAvg = 0;
            if(rp != 0){
                rightAvg = right/rp;
            }
            int curr = (int)abs(leftAvg - rightAvg);
            if(mini > curr){
                mini = curr;
                ans = i;
            }
        }
        return ans;
    }
};