class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            vector<int> answer;
            int n = nums.size();
            for(int i = 0; i < n; i++){
                answer.push_back(nums[nums[i]]);
            }
            return answer;
        }
    };