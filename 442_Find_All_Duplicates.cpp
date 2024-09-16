class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int a = abs(nums[i]);
            if(nums[a-1] < 0){
                ans.push_back(a);
            }
            nums[a-1] *= -1;
            
        }
        return ans;
    }
};