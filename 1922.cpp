class Solution {
public:
    long long MOD = 1000000007;
    long long powerN(long long x, long long n){
        if(n==0){
            return 1;
        }
        x = x%MOD;
        if(n%2==0){
            long long half = powerN(x,n/2);
            return (half*half)%MOD;
        }else{
            long long half = powerN(x,(n-1)/2);
            return (x*((half*half)%MOD))%MOD;
        }
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return powerN(5,even)*powerN(4,odd)%MOD;
    }
};