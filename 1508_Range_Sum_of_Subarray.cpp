class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int low = 0;
        int high = 0;
        int sum = 0;
        while(low < n){
            if(high!=n){
                sum += nums[high];
                ans.push_back(sum);
                high++;
            }
            if(high == n){
                low++;
                high = low;
                sum = 0;
            }
        }
        long long rangeSum = 0;
        sort(ans.begin(),ans.end());
        for(int i = left-1; i < right; i++){
            rangeSum = (rangeSum +  ans[i])%1000000007;
        }
        return rangeSum;
    }
};