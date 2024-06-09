class Solution {
public:
    int fib(int n) {
        int r = 0, t0 = 0, t1 = 1;
        if(n==0 || n==1){
            return n;
        }
        for(int i = 2; i<=n;i++){
            r = t0+t1;
            t0 = t1;
            t1 = r;
        }
        return r;
    }
};