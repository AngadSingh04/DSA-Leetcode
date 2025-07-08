class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int> vc(nums.size());

        // for(int i = 0; i < nums.size(); i++){
        //     vc[(i+k)%nums.size()] = nums[i];
        // }

        // nums = vc;

        k = k%nums.size();

        int i = 0;
        int j = nums.size()-1;
        while(i < j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }

        for(int i = 0; i < k/2; i++){
            swap(nums[i], nums[k-1-i]);
        }
        for(int i = k, j = nums.size()-1; i < j; j--, i++){
            swap(nums[i],nums[j]);

        }
    }
};