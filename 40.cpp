class Solution {
public:
    void getSet(vector<int>& arr, int target, int ind, vector<vector<int>>& ans, vector<int>& vc){
        if(target == 0){
            ans.push_back(vc);
            return;
        }

        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i] > target){
                break;
            }

            vc.push_back(arr[i]);
            getSet(arr,target-arr[i], i+1, ans, vc);
            vc.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> vc;
        int ind = 0;
        getSet(arr,target,ind, ans,vc);
        return ans;
    }
};