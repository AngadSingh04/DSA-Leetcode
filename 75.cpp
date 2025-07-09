class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[i],nums[mid]);
                i++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};