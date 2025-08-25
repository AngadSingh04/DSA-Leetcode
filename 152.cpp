class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        long long prefix = 1;
        long long suffix = 1;
        
        int n = arr.size();
        
        long long maxi = INT_MIN;
        
        for(int i = 0; i < n; i++){
            if(arr[i] != 0){
                prefix *= arr[i];
                maxi = max(maxi,prefix);
            }else{
                maxi = max(maxi, 0LL);
                prefix = 1;
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            if(arr[i] != 0){
                suffix *= arr[i];
                maxi = max(maxi,suffix);
            }else{
                maxi = max(maxi,0LL);
                suffix = 1;
            }
        }
        
        return (int)maxi;
        
        
    }
};