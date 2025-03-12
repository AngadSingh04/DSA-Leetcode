class Solution {
    public:
        int binarySearch(vector<int> nums, int key, int low, int high){
            int result = nums.size();
            while(low <= high){
                int mid = (low+high)/2;
                if(nums[mid] < key){
                    low=mid+1;
                }else{
                    result = mid;
                    high = mid - 1;
                }
            }
            return result;
        }
        int maximumCount(vector<int>& nums) {
            int low = 0;
            int high = nums.size()-1;
            int neg_count = binarySearch(nums, 0, low, high);
            int pos_count = nums.size()-binarySearch(nums,1, low, high);
            return max(neg_count,pos_count);
        }
    };