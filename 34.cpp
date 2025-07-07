class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low1 = 0;
        int high1 = nums.size();
        vector<int> ans;

        if(nums.size() == 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        while(low1 < high1){
            int mid = low1 + (high1-low1)/2;
            if(nums[mid] < target){
                low1 = mid+1;
            }else{
                high1 = mid;
            }
        }
        int a = low1;

        if(a >= nums.size() || nums[a] != target){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }


        int low2 = 0;
        int high2 = nums.size();

        while(low2 < high2){
            int mid = low2 + (high2 - low2)/2;
            if(nums[mid] <= target){
                low2 = mid+1;
            }else{
                high2 = mid;
            }
        }
        int b = low2-1;
        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};