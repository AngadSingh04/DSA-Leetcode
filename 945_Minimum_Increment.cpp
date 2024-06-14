
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m = nums.size();
        int count = 0;
        for(int i = 1; i < m; i++){
            while(nums[i] <= nums[i-1]){
                nums[i]++;
                count++;
            }
        }
        return count;
    }
};


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m = nums.size();
        int count = 0;
        for(int i = 1; i < m; i++){
            if(nums[i] <= nums[i-1]){
                int a = nums[i-1] - nums[i] + 1;
                nums[i] = nums[i] + a;
                count = count + a;
            }
        }
        return count;
    }
};