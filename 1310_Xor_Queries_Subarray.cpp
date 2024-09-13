class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> p(arr.size(),0);
        p[0] = arr[0];
        for(int i = 1; i < p.size(); i++){
            p[i] = arr[i]^p[i-1];
        }
        vector<int> ans(queries.size(),0);
        for(int i = 0; i < ans.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            if(left == 0){
                ans[i] = p[right];
            }else{
                ans[i] = p[right] ^ p[left-1];
            }
        }
        return ans;
    }
};