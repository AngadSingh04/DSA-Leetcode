// remember: for n < 10, 7 is the only happy number except for 1

class Solution {
public:
    bool isHappy(int n) {
        if(n == 1 || n == 7){
            return true;
        }
        while(n >= 10){
            int a = 0;
            while(n > 0){
                int rem = n%10;
                a += (rem*rem);
                n = n/10;
            }
            if(a == 1|| a==7){
                return true;
            }
            n = a;
        }
        
        return false;
    }
};