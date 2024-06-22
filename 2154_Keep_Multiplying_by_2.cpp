class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int sum = 0;
        while(true){
            bool found = false;
            for(int i = 0; i < nums.size(); i++){
            if(nums[i] == original){
                original = original *2;
                found = true;
                break;
            }
        }
        if(!found){
            break;
        }
        }
        
        return original;
    }
};