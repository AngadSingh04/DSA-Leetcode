class Solution {
public:
    int MOD = 1e9 + 7;
    int getPow(long long n, long p){
        if(p == 0){
            return 1;
        }
        if(p%2 == 0){
            long long tmp = (n*n)%MOD;
            return getPow(tmp, p/2);
        }else{
            long long  tmp = (n*n)%MOD;
            return (n*getPow(tmp, (p-1)/2))%MOD;
        }
    }
    int countGoodNumbers(long long n) {
        long long eInd = (n+1)/2;
        long long oInd = n/2;

        int getEven = getPow(5, (long)eInd) ;
        int getOdd = getPow(4, (long)oInd);
        return ((long long)getEven * getOdd)%MOD;
    }
};