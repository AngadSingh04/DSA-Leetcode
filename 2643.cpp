class Solution {
public:
    int getLower(vector<int>& arr, int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        // 0 0 0 1 1
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = -1;
        int ind = -1;
        // sort(mat.begin(),mat.end());

        for(int i = 0; i < n; i++){
            vector<int> vc = mat[i];
            sort(vc.begin(), vc.end());
            int tmp = m - getLower(vc, 1);
            if(tmp > maxi){
                maxi = tmp;
                ind = i;
            }
        }

        return {ind, maxi};
    }
};