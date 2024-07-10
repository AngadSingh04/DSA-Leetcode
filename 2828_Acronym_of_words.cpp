class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(s.length()!= words.size()){
            return false;
        }
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < words.size();j++){
                string a = words[i];
                if(a[0] != s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};