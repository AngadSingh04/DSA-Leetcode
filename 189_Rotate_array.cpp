class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            vector<int> answer(nums.size());
            for(int i = 0; i < answer.size(); i++){
                answer[(i+k)%nums.size()]=nums[i];
            }
            nums = answer;
        }
    };