class Solution {
public:
    bool checkPerfectNumber(int num) {
        // if num = 1 then it cannot be a perfect divisor
        if(num==1){
            return false;
        }
        int sum = 1;
        // if we start from i = 1, then it willinclude the num value also 
        for(int i = 2; i <= sqrt(num); i++){
            if(num%i==0){
                sum += i;
                if(num/i != i){
                    sum += (num/i);
                }
            }
        }
        if(sum==num){
            return true;
        }
        return false;
    }
};