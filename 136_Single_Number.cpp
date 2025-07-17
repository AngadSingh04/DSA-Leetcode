class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        int uniqNumber = 0;
        for(int i = 0; i < size; i++){
            uniqNumber ^= nums[i];
        }
        return uniqNumber;
    }
};