class Solution {
public:
    int getSum(vector<int>& weights){
        int n = weights.size();

        int sum = 0;
        for(int i = 0;i < n; i++){
            sum += weights[i];
        }
        return sum;
    }
    int getDays(vector<int>& weights, int mid, int days){
        int d = 0;
        int tmp = 0;
        for(int i = 0; i < weights.size(); i++){
            tmp += weights[i];
            if(tmp == mid){
                d++;
                tmp = 0;
            }else if(tmp > mid){
                d++;
                tmp = weights[i];
            }
        }
        if(tmp!= 0){
            d++;
        }

        return d <= days;
    }
    int getMax(vector<int>& a){
        int maxi = INT_MIN;
        for(int i = 0; i < a.size(); i++){
            maxi = max(maxi, a[i]);   
        }
        return maxi;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = getMax(weights);
        int high = getSum(weights);
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(getDays(weights, mid, days)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};