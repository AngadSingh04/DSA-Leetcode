class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
       unordered_map<int, int> na;
       for(auto it: nums){
         na[it]++;
       }
       sort(nums.begin(),nums.end(), [&](int a, int b){
        return na[a] != na[b] ? na[a] < na[b] : a > b;
       });
       return nums;
    }
};