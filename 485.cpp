class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int maxi = 0;
        while(i < nums.size()){
            int count = 0;
            while(i < nums.size() && nums[i] == 0){
                i++;
            }
            while(i < nums.size() && nums[i] == 1){
                count++;
                i++;
            }


            maxi = max(maxi, count);
        }

        return maxi;
    }
};