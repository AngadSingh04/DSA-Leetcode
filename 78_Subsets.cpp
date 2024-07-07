class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int s = pow(2,n);
        vector<vector<int>> ans;

        for(int i = 0; i < s; i++){
            int xr = 0;
            vector<int> a;
            for(int j = 0; j < n; j++){
                if((1<<j)&i){
                    a.push_back(nums[j]);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};