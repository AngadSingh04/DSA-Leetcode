class Solution {
    public:
        int getPivot(vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;
    
        while(low < high){
            int mid = (low + (high-low)/2);
            if(nums[mid]>=nums[0]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
    
        int binarySearch(vector<int>& nums, int l, int h, int target){
            int low = l;
            int high = h;
    
            while(low <= high){
                int mid = (low + (high-low)/2);
                if(nums[mid]==target){
                    return mid;
                }else if(nums[mid] > target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            return -1;
        }
        int search(vector<int>& nums, int target) {
            int pivot = getPivot(nums);
            // int ans = -1;
            if(target >= nums[pivot] && target <= nums[nums.size()-1]){
                return  binarySearch(nums, pivot, nums.size()-1,target);
            }else{
                return binarySearch(nums, 0, pivot-1, target);
            }
        }
    };