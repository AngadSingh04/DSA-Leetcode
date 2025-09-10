class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n,1);
        vector<int> tmp(n);
        for(int i = 0; i < n; i++){
            tmp[i] = i;
        }
        
        
        int maxi = 0;
        int index = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0 && dp[i] <= dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    tmp[i] = j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                index = i;
            }
        }
        
        vector<int> ans;
        while(tmp[index] != index){
            ans.push_back(arr[index]);
            index = tmp[index];
        }
        ans.push_back(arr[index]);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};