class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int low = i + 1;
            int high = nums.size() -1;
            while(high > low){
                if((nums[low] - nums[i]) == diff && (nums[high] - nums[low]) == diff){
                    count++;
                    low++;
                    high--;
                }else if(nums[low]-nums[i] < diff || nums[high]- nums[low] < diff){
                    low++;
                }else{
                    high--;
                }

            }
        }
        return count;
    }
};