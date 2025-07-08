class Solution {
public:
    int myAtoi(string s) {
        int l = 0;
        int sl = s.size();
        long long ans = 0;
        bool isNeg = false;

        

        while(l < sl && s[l] == ' '){
            l++;
        }

        if(s[l] == '-' || s[l] == '+'){
            if(s[l] == '-'){
                isNeg = true;
            }
            l++;
        }

        while(l < sl && s[l] >= '0' && s[l] <= '9'){

            while(l < sl && s[l] == '0'){
                l++;
            }
            if(l >= sl){
                break;
            }
            while(l < sl && s[l] >= '0' && s[l] <= '9'){
                int rem = s[l] - '0';
                if(ans > (INT_MAX / 10)){
                    return isNeg ? INT_MIN : INT_MAX;
                }
                ans *= 10;
                if(ans > (INT_MAX - rem)){
                    return isNeg ? INT_MIN : INT_MAX;
                }
                ans += rem;
                l++;
            }
        }
        if(isNeg){
            ans = -ans;
            if(ans < INT_MIN){
                return INT_MIN;
            }
        }else{
            if(ans > INT_MAX){
                return INT_MAX;
            }
        }
        return ans;
    }
};