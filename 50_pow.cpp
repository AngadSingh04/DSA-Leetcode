class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1.00000;
        }
        double result = 1.0;
        long a = abs((long)n);
        while (a > 0) {
            if (a % 2 == 1) { 
                result *= x;
            }
            x *= x; 
            a /= 2; 
        }
        
        return n < 0 ? 1.0 / result : result;
    }
};