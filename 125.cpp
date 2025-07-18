class Solution {
public:
    bool checkPal(string& ss, int low, int high){
        if(low >= high){
            return 1;
        }
        if(ss[low]!=ss[high]){
            return 0;
        }

        return checkPal(ss,low+1,high-1);
    }
    bool isPalindrome(string s) {
        string ss = "";
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                ss += tolower(s[i]);
            }
            
        }
        int low = 0;
        int high = ss.size()-1;
        bool ans = checkPal(ss,low,high);

        return ans;
    }
};