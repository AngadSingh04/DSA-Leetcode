class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> n1(nums1.begin(),nums1.end());
        unordered_set<int> n2(nums2.begin(),nums2.end());
        unordered_set<int> result1;
        unordered_set<int> result2;
        for(auto num1: nums1){
            if(n2.find(num1) == n2.end()){
                result1.insert(num1);
            }
        }

        for(auto num2: nums2){
            if(n1.find(num2) == n1.end()){
                result2.insert(num2);
            }
        }
        ans[0].assign(result1.begin(),result1.end());
        ans[1].assign(result2.begin(),result2.end());
        return ans;
    }
};