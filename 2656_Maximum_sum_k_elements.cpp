class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int temp = 0;
        for(int i = 0; i < k; i++){
            temp = temp + nums[nums.size()-1];
            nums[nums.size()-1]++;
        }
        return temp;
    }
};