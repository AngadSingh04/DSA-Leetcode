class Solution {
public:
    double getPow(double x, long n){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return getPow(1/x, -n);
        }
        if(n%2 == 0){
            return getPow(x*x, n/2);
        }else{
            return x * getPow(x*x, (n-1)/2);
        }
    }
    double myPow(double x, int n) {
        return getPow(x, (long)n);
    }
};