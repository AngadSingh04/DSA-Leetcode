class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> common;
        unordered_set<int> answer(nums1.begin(),nums1.end());
        for(int i = 0; i < nums2.size(); i++){
            if(answer.find(nums2[i]) != answer.end()){
                common.insert(nums2[i]);
            }
        }
        vector<int> ans(common.begin(), common.end());
        return ans;
    }
};