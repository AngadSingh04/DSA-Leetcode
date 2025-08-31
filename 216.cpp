class Solution {
public:
    void getSet(vector<vector<int>>& ans, vector<int>& arr, vector<int>& vc, int ind, int k, int n){
        if(n == 0){
            if(vc.size() == k){
                ans.push_back(vc);
            }
            return;
        }

        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i] > n){
                break;
            }
            vc.push_back(arr[i]);
            getSet(ans, arr, vc, i+1, k, n - arr[i]);
            vc.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> vc;
        int ind = 0;

        getSet(ans,arr,vc,ind,k,n);
        return ans;
    }
};