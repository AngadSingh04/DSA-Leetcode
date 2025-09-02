class Solution {
public:
    int getSum(vector<int>& arr){
        int prev = arr[0];
        int prev2 = 0;
        int curr = 0;

        for(int i = 1; i < arr.size(); i++){
            int pick = arr[i];
            if(i > 1){
                pick += prev2;
            }
            int nPick = prev;
            curr = max(pick, nPick);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> tmp1,tmp2;
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        for(int i = 0; i < n; i++){
            if(i != 0){
                tmp1.push_back(nums[i]);
            }
            if(i != n-1){
                tmp2.push_back(nums[i]);
            }
        }

        return max(getSum(tmp1),getSum(tmp2));
    }
};