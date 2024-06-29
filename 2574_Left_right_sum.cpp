class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n,0);
        vector<int> rightsum(n,0);
        vector<int> ans;
        int suml = 0;
        int sumr = 0;
        for(int i = 1; i < nums.size(); i++){
            suml += nums[i-1];
            leftsum[i] = suml;
        }
        for(int i = nums.size()-1; i >= 1; i--){
            sumr += nums[i];
            rightsum[i-1] = sumr; 
            
        }
        for(int i = 0; i < n; i++){
            int res = abs(leftsum[i] - rightsum[i]);
            ans.push_back(res);
        }
        return ans;
    }
};