class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0;
        int r = 0;
        // 0,1,2,3,4
        // 2,3,1,1,4
        //   l
        //     r

        while(r < nums.size()-1){
            int range = 0;
            for(int i = l; i <= r; i++){
                range = max(range, i+nums[i]);
            }
            l = r+1; // 1
            r = range; // 2
            jumps++;
        }

    return jumps;
        
    }
};