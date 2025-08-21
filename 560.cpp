class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> um;
        int count = 0;
        int subSum = 0;

        um[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            subSum += nums[i];

            int prevSum = subSum - k;
            if(um.find(prevSum) != um.end()){
                count = count + um[prevSum]; // count = 5
            }

            um[subSum]++;
        }

        return count;
        
    }
};