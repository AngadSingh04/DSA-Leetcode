class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        unordered_map<int,int> um;
        for(int i = 0; i < nums.size(); i++){
            um[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(um[nums[i]]==1){
                sum += nums[i];
            }
        }
        return sum;
    }
};