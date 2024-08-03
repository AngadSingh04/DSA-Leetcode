class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // long long curr = 0;
        long long max_ans = 0;

        for(int i = 0; i < nums.size()-2; i++){
            long long a = nums[i];
            for(int j = i+1; j < nums.size()-1; j++){
                long long b = nums[j];
                for(int k =j+1; k < nums.size(); k++){
                    long long c = nums[k];
                    if((a-b)*c > max_ans){
                        max_ans = (a-b)*c;
                    }
                }
            }
        }
        return max_ans;
    }
};