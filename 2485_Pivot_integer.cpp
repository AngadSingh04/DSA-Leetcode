class Solution {
public:
    int pivotInteger(int n) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 1; i <=n; i++){
            sum1 += i;
        }
        for(int j = 1; j <=n; j++){
            sum1 -= j;
            if(sum1 == sum2){
                return j;
            }else{
                sum2 += j;
            }
        }
        return -1;
    }
};