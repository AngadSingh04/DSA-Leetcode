class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums[nums.size()-1];
        int b = nums[0];
        int ans = 0;
        for(int i = b; i > 0; i--){
            if(a%i==0 && b%i==0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};