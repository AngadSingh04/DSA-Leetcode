class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        // [1,2,2,5,6,6]

        sort(nums.begin(),nums.end());
        int total = 0;
        for(int i = 0; i < nums.size(); i = i+2){
            total += nums[i];
        }

        return total;


    }
};