class Solution {
public:
    double po(double x, long n){
        if(n==0){
            return 1;
        }
        if(n < 0){
            return po(1/x, -n);
        }
        if(n%2==0){
            return po(x*x,n/2);
        }else{
            return x*po(x*x,(n-1)/2);
        }
    }
    double myPow(double x, int n) {
        return po(x,long(n));
    }
};