class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int a = arr.size();
        int remove = a/20;
        double sum = 0;
        for(int i = 0; i < a; i++){
            sum += arr[i];
        }
        for(int i = 0; i < remove; i++){
            sum -= (arr[i] + arr[a-1-i]);
        }
        double ans = 0.0;
        ans = sum/(a-remove*2);
        return ans;
        
    }
};