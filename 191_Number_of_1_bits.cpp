class Solution {
public:
    int hammingWeight(int n) {
        // int i = 0;
        // int count = 0;
        // for(int i = 0; i < 32; i++){
        //     if((n&(1<<i)) != 0){
        //         count++;
        //     } 
        // }
        // return count;

        int i = 0;
        int count = 0;
        while(n!=0){
            if(n&1 == 1){
                count++;
            }

            n = n >> 1;
        }
        return count;
    }
};