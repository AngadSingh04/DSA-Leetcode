// logic 
// j-i != nums[j] - nums[i] --> bad pair
//this can be written as
// j-nums[j]!=i-nums[i] ans i - nums[i] == j - nums[j] ---> good pair

//bad pair = total pair - good pair

//total number of pairs = (n(n-1)/2)

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<int,int> gp;
        long n = nums.size();   
        for(int i = 0; i < n; i++){
            if(gp.find(i-nums[i]) != gp.end()){
                count += gp[i-nums[i]];
            }
            gp[i-nums[i]]++;
        }
        long tp = n*(n-1)/2;
        return tp - count;

    }
};