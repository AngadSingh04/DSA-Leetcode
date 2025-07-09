class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int suma = 0;
        int sumb = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            suma += nums[i];
        }

        for(int i = 0; i <= n; i++){
            sumb += i;
        }

        int total = sumb - suma;
        return total;

    }
};