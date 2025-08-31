class Solution {
public:
    void getSet(vector<int>& nums, vector<vector<int>>& ans, vector<int>& vc, int ind){
        ans.push_back(vc);

        for(int i = ind; i < nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]){
                continue;
            }
            vc.push_back(nums[i]);
            getSet(nums,ans,vc,i+1);
            vc.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> vc;
        int ind = 0;

        getSet(nums, ans, vc, ind);
        return ans;

    }
};