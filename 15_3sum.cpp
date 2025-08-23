class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int i = 0;
        sort(nums.begin(),nums.end());
        while(i < n){
            if(i > 0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }
            int j = i+1;
            int k = n-1;

            while(j < k){
                int tmp = nums[i]+nums[j]+nums[k];
                if(tmp == 0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    while(j < k && nums[j] == nums[j+1]){
                        j++;
                    }
                    j++;
                    while(j < k && nums[k] == nums[k-1]){
                        k--;
                    }
                    k--;
                }else if(tmp < 0){
                    j++;
                }else{
                    k--;
                }
            }
            i++;
        }

        return ans;
    }
    // 1 2 2 2 2 3
};