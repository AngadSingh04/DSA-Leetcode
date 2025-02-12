class Solution {
    public:
        int findComplement(int num) {
            int a = num;
            int mask = 0;
            while(a != 0){
                a = a >> 1;
                mask = mask << 1;
                mask = mask | 1;
            }
    
            return ~num & mask;
        }
    };