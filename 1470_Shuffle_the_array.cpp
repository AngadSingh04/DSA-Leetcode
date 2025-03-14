class Solution {
    public:
        vector<int> shuffle(vector<int>& nums, int n) {
            vector<int> ans(nums.size());
            for(int i = 0; i < nums.size()/2; i++){
                ans.push_back(nums[i]);
                ans.push_back(nums[nums.size()/2 + i]);
            }
            return ans;
        }
    };