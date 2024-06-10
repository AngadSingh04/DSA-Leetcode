class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> myarr(nums.size());
        for(int i = 0; i<myarr.size();i++){
            myarr[i] = 0;
        }
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<nums.size();j++){
                if(nums[i]>nums[j]){
                    myarr[i]++;
                }
            }
        }
        return myarr;
    }
};