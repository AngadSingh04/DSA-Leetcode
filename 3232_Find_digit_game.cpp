class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int dN = 0;
        int sN = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 10){
                dN += nums[i];
            }else{
                sN += nums[i];
            }
        }
        if(dN == sN){
            return false;
        }
        return true;
    }
};