class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 0;
        int s = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > l){
                s = l;
                l = nums[i];
            }else{
                s = max(s,nums[i]);
            }
        }
        return (l-1)*(s-1);
    }
};