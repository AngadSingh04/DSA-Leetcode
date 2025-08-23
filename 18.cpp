class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        while(i < n){
            int j = i+1;
            if(i > 0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }
            while(j < n){
                int k = j+1;
                int l = n-1;

                if(j > i+1 && nums[j] == nums[j-1]){
                    j++;
                    continue;
                }

                while(k < l){
                    long long tmp = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(tmp == target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);

                        while(k < l && nums[k] == nums[k+1]){
                            k++;
                        }
                        while(k < l && nums[l] == nums[l-1]){
                            l--;
                        }
                        k++;
                        l--;
                    }else if(tmp < target){
                        k++;
                    }else{
                        l--;
                    }
                }
                j++;
            }
            i++;
        }

        return ans;
    }
};