class Solution {
public:
    int maxScore(string s) {
        int result = INT_MIN;
        // score = zl + or
        // or = ot - ol
        // score = zl + ( ot - ol)
        //score = (zl - ol) + ot(constant)

        int zero = 0;
        int one = 0;
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == '0'){
                zero++;
            }else{
                one++;
            }

            result = max(result, zero - one);
        }
        if(s[s.size()-1] == '1'){
            one++;
        }
        return result+one;
    }
};