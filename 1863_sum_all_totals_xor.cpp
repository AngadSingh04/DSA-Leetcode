class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int n = nums.size();
            int s = pow(2,n);
            int ans = 0;
            for(int i = 0; i < s; i++){
                int xr = 0;
                for(int j = 0; j < n; j++){
                    if((1<<j) & i){
                        xr ^= nums[j];
                    }
                }
                ans += xr;
            }
            return ans;
        }
    };