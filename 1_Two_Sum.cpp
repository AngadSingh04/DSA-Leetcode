class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;

        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            int lef = target - temp;

            if(um.find(lef) != um.end()){
                return {um[lef],i};
            }

            um[nums[i]] = i;
        }
        return {};
    }
};