class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> Nnums;
        Nnums.insert(Nnums.end(), nums.begin(), nums.end());
        Nnums.insert(Nnums.end(), nums.begin(), nums.end());

        int count1 = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i]==1){
                count1++;
            }
        }
        int currentW = 0;
        int maxW = 0;
        for(int i = 0; i < count1; i++){
            if(Nnums[i]==1){
                currentW++;
            }
        }
        maxW = currentW;
        for(int i = count1; i < Nnums.size(); i++){
            if(Nnums[i]==1){
                currentW++;
            }
            if(Nnums[i-count1]==1){
                currentW--;
            }
            maxW = max(currentW, maxW);
        }
        return count1 - maxW;
    }
};