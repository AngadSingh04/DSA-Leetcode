class Solution {
public:
    int getMin(vector<int>& arr){
        int n = arr.size();
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            mini = min(mini, arr[i]);
        }
        return mini;
    }
    int getMax(vector<int>& arr){
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
    
    int getB(vector<int>& arr, int mid, int k){
        int cnt = 0;
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(mid >= arr[i]){
                cnt++;
            }else{
                ans = ans + cnt/k;
                cnt = 0;
            }
        }
        ans = ans + cnt/k;
        
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = getMin(bloomDay);
        int high = getMax(bloomDay);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(getB(bloomDay,mid,k) >= m){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};