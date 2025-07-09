class Solution {
public:

    void revR(vector<int>& nums, int l, int h){
        while(l < h){
            swap(nums[l],nums[h]);
            l++;
            h--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int brk = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                brk = i;
                break;
            }
        }

        if(brk == -1){
            revR(nums, 0, n-1);
        }else{
            for(int i = n-1; i >= brk; i--){
            if(nums[i] > nums[brk]){
                swap(nums[i],nums[brk]);
                break;
            }
        }

        revR(nums, brk+1, n-1);
        }
    }
};