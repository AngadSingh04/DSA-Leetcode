class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int num: nums){
            sum += num;
        }
        long long left = 0;
        long long right = sum;
        int count = 0;
        for(int i = 0; i < nums.size()-1; i++){
            left += nums[i];
            right -= nums[i];
            if(left >= right){
                count++;
            }
        }
        return count;
    }
};