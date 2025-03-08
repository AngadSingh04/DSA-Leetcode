class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int black_cnt = 0, ans = INT_MAX;
            
            for (int i = 0; i < blocks.size(); i++) {
    
                if (i - k >= 0 && blocks[i - k] == 'B'){
                    black_cnt--;
                }
                if (blocks[i] == 'B') black_cnt++;
                ans = min(ans, k - black_cnt);
            }
            
            return ans;
        }
    };