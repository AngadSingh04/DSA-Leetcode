class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            int ss = s.length();
            bool istrue = true;
            for(int j = 0; j < ss; j++){
                if(s[j]!=s[ss - 1 -j]){
                    istrue = false;
                }
            }
            if(istrue == true){
                return s;
            }
        }
        return "";
    }
};