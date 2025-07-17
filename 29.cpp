class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        bool isNeg = false;
        if(dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0){
            isNeg = true;
        }

        long n = abs(dividend);
        long d = abs(divisor);

        long ans = 0;

        while(n >= d){
            int count = 0;
            while(n >= (d << (count+1))){
                count++;
            }
            ans += 1 << count;
            n -= d << count;
        }
        if(ans == (1<<31) && !isNeg){
            return INT_MAX;
        }
        if(ans == (1<<31) && isNeg){
            return INT_MIN;
        }

        return isNeg ? ans*-1: ans;
    }
};