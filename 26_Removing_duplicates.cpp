class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            unordered_set<int> sett(nums.begin(), nums.end());
            
            vector<int> vec;
            vec.assign(sett.begin(), sett.end());
            int n = vec.size();
            for(int i=0;i<n;i++){
                nums[i] = vec[i];
            }
            sort(nums.begin(), nums.begin()+n);
            return n;
        }
    };