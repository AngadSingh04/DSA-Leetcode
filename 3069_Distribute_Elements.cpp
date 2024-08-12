class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        arr1.push_back(nums[0]);
        vector<int> arr2;
        arr2.push_back(nums[1]);
        for(int i = 2; i < nums.size(); i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }
        vector<int> ans(arr1.begin(), arr1.end());
        for(int i = 0; i < arr2.size(); i++){
            ans.push_back(arr2[i]);
        }
        return ans;
    }
};