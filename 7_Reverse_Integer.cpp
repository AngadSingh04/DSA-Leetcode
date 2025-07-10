class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool isNeg = false;
        if(x < 0){
            isNeg = true;
        }
        while(x != 0){
            int rem = x%10;
            if(ans > (INT_MAX)/10 || ans < (INT_MIN)/10){
                return 0;
            }
            ans = ans*10 + rem;
            x = x/10;
        }
        // if(isNeg){
        //     return ans*-1;
        // }

        return ans;
    }
};