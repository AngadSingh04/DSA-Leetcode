class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<=2){
            return -1;
        }
        sort(nums.begin(), nums.end());
        return nums[1];
    }
};

// For better Runtime
auto fast_io = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
} ();