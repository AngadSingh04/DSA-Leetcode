class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int total_subsets = (1<<size);
        vector<vector<int>> ans;

        for(int i = 0; i < total_subsets; i++){
            vector<int> tmp;
            for(int j = 0; j < size; j++){
                if(i & (1 << j)){
                    tmp.push_back(nums[j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};