class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int i = 0; i < nums.size(); i++){
            um[nums[i]]++;
        }
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++){
            if(um[nums[i]]==2){
                us.insert(nums[i]);
            }
        }
        vector<int> ans(us.begin(),us.end());
        return ans;
    }
};