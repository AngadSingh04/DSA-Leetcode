class Solution {
    public:
        int bitwiseComplement(int n) {
            int mask = 0;
            int ans = n;
            if(n == 0){
                return 1;
            }
            while(ans != 0){
                ans = ans >> 1;
                mask = (mask << 1);
                mask = mask | 1;
            }
            int a = mask & (~n);
            return a;
        }
    };