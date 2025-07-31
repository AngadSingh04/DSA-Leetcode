class Solution {
public:
    bool canJump(vector<int>& nums) {

        if(nums.size() == 1){
            return true;
        }
        
       int maxInd = 0;
       for(int i = 0;i<nums.size();i++){
        if(i > maxInd){
            return false;
        }
        int minN = nums[i] + i;
        maxInd = max(maxInd, minN);
       }

       if(maxInd >= nums.size()-1){
        return true;
       }
       return false;
    }
};