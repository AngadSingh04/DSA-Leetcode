class Solution {
public:
    int getMin(vector<int>& nums){
        int mini = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mini = min(mini,nums[i]);
        }
        return mini;
    }

    int getMax(vector<int>& nums){
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }

    int getVal(vector<int>& nums, int threshold,int mid){
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            cnt += ceil((double)nums[i]/ (double)mid);
        }
        return cnt <= threshold;
    }
    // 1 2 3 4 5 6
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = getMax(nums);
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(getVal(nums,threshold,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};