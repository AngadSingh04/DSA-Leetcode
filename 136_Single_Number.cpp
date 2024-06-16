class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                sum -= (nums[i]*2);
            }
        }
        return sum;
    }
};