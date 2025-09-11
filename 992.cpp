class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> um;
        int cnt1 = 0;
        int cnt2 = 0;

        int l = 0;
        int r = 0;

        while(r < n){
            um[nums[r]]++;
            while(um.size() > k){
                um[nums[l]]--;
                if(um[nums[l]] == 0){
                    um.erase(nums[l]);
                }
                l++;
            }

            int len = r-l+1;
            cnt1 += len;
            r++;
        }
        um.clear();
        l = 0;
        r = 0;

        while(r < n){
            um[nums[r]]++;
            while(um.size() > k-1){
                um[nums[l]]--;
                if(um[nums[l]] == 0){
                    um.erase(nums[l]);
                }
                l++;
            }

            int len = r-l+1;
            cnt2 += len;
            r++;
        }

        return cnt1 - cnt2;
    }
};