class Solution {
  public:
    bool getTrue(int n, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(sum == 0){
            return true;
        }
        if(n == 0){
            return (arr[0] == sum);
        }
        
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        bool pick = false;
        if(arr[n] <= sum){
            pick = getTrue(n-1, sum - arr[n], arr,dp);
        }
        bool nPick = getTrue(n-1,sum,arr,dp);
        
        return dp[n][sum] = pick || nPick;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        
        if(sum%2 == 1){
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        return getTrue(n-1, sum/2, arr,dp);
    }
};