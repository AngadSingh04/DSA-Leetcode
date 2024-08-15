class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minA = INT_MAX;
        for(int i = 1; i < arr.size(); i++){
            int res = abs(arr[i]-arr[i-1]);
            if(res < minA){
                minA = res;
            }
        }
        vector<vector<int>> ans;
        for(int i = 1; i < arr.size(); i++){
            if(abs(arr[i]-arr[i-1]) == minA){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};