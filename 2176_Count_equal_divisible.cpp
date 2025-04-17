class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[i] == nums[j] && (i*j) % k == 0){
                        count++;
                    }
                }
            }
            return count;
            
        }
    };

    //second way 

    class Solution {
        public:
            int rcount(vector<int>& nums, int k, int i){
                if(i >= nums.size()){
                    return 0;
                }
                int count = 0;
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[i]==nums[j] && (i*j)%k==0){
                        count++;
                    }
                }
        
                return count + rcount(nums, k, i+1);
            }
            int countPairs(vector<int>& nums, int k) {
                return rcount(nums,k, 0);
            }
        };