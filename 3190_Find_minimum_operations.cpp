class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int opr = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]%3 == 1 || nums[i]%3 == 2){
                opr += 1;
            }
        }
        return opr;
    }
};