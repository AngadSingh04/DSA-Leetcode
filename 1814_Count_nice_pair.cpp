class Solution {
public:
    int rev(int x){
        int a = 0;
        while(x > 0){
            int rem = x%10;
            a = a * 10 + rem;
            x /=10;
        }
        return a;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        unordered_map<int,int> np;
        int M = 1000000007;
        for(int i = 0; i < n; i++){
            int K = nums[i] - rev(nums[i]);
            if(np.find(K) != np.end()){
                count = (count + np[K])%M;
            }
            np[K]++;
        }
        return count;
    }
};