class Solution {
public:

    void getSet(vector<int>& arr, int target, int ind, vector<int>& vc, vector<vector<int>>& ans){
        if(arr.size() == ind){
            if(target == 0){
                ans.push_back(vc);
            }
            return;
        }

        if(arr[ind] <= target){
            vc.push_back(arr[ind]);
            getSet(arr, target - arr[ind], ind, vc,ans);
            vc.pop_back();
        }

        getSet(arr,target,ind+1,vc,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int ind = 0;
        vector<int> vc;
        vector<vector<int>> ans;
        getSet(candidates, target, ind, vc, ans);
        return ans;
    }
};