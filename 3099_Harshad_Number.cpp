class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int dsum = 0;
        int a = x;
        if(x < 10 && x > 0){
            return x;
        }
        if(x >= 10){
            while(x > 0){
                int rem = x % 10;
                dsum += rem;
                x = x/10;
            }
            if(a%dsum == 0){
                return dsum;
            } 
        }
        return -1;
    }
};