class Solution {
public:
    int maxEle(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    long long getHrs(vector<int>& piles, int mid){
        long long totalH = 0;

        for(int i = 0; i < piles.size(); i++){
            totalH += ceil((double)piles[i]/ (double)mid);
        }

        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high  = maxEle(piles);

        while(low <= high){
            int mid = low + (high - low)/2;
            long long hrs = getHrs(piles,mid);
            if(hrs <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};