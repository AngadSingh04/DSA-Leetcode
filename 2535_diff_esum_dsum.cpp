class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        long esum = 0;
        for(int i = 0; i < nums.size(); i++){
            esum += nums[i];
        }
        long dsum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 10){
                while(nums[i] > 0){
                    long rem = nums[i]%10;
                    dsum += rem;
                    nums[i] = nums[i]/10;
                }
            }else{
                dsum += nums[i];
            }
        }
        return esum-dsum;
    }
};