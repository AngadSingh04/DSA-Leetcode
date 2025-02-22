class Solution {
    public:
        char tolower(char ch){
            if(ch >= 'a' && ch <= 'z'){
                return ch;
            }else{
                return ch - 'A' + 'a';
            }
        }
        bool isokay(char ch){
            if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9'){
                return true;
            }
            return false;
        }
        bool isPalindrome(string s) {
            int low = 0;
            int high = s.length()-1;
    
            while(low < high){
                while(low < high && !isokay(s[low])){
                    low++;
                }
                while(low < high && !isokay(s[high])){
                    high--;
                }
                if(tolower(s[low])!=tolower(s[high])){
                    return false;
                }
                low++;
                high--;
            }
            return true;
        }
    };