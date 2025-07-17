class Solution {
public:
    int minBitFlips(int start, int goal) {
        // 1010
        // 0111

        // 1 1 0 1

        int tmp = start^goal;
        int count = 0;
        while(tmp!=0){
            if((tmp & 1) == 1){
                count++;
            }
            tmp = tmp >> 1;
        }
        return count;
    }
};