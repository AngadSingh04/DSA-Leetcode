class Solution {
public:
    int getPoint(vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;

        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= nums[0]){
                low = mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
    int bS(vector<int>& nums, int low, int high, int target){
        int l = low;
        int h = high;

        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int point = getPoint(nums);
        if(target >= nums[point] && target <= nums[nums.size()-1]){
            return bS(nums, point, nums.size()-1,target);
        }else{
            return bS(nums, 0, point, target);
        }
    }
};