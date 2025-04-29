class Solution {
    public:
            long long countSubarrays(vector<int>& nums, int k, int s = 0) {
            long maxi = *max_element(nums.begin(), nums.end()), curr = 0, res = 0; 
            for(int e = 0; e < nums.size(); e++){
                if(nums[e] == maxi) curr++; 
                while(curr >= k){
                    if (nums[s] == maxi) curr--; 
                    s++;
                }
                res += s;
            }
            return res;
        }
    };