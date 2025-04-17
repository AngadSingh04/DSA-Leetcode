class Solution {
    public:
        string largestOddNumber(string num) {
            for(int i = num.length()-1; i >= 0; i--){
                int dig = num[i] - '0';
                if(dig%2 != 0){
                    string a = num.substr(0,i+1);
                    return a;
                }
            }
            return "";
        }
    };