class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> array;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            double avg = (nums[i] + nums[n - 1 -i])/2.0;
            array.push_back(avg);
        }
        double minN = numeric_limits<double>::max();
        for(int i = 0; i < array.size(); i++){
            double curr = array[i];
            if(minN > curr){
                minN = curr;
            }
        }
        return minN;
    }
};