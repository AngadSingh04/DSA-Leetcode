class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int p = pref.length();
        for(int i = 0; i < words.size(); i++){
            string a = words[i];
            if(a.substr(0,p)==pref){
                count++;
            }
        }
        return count;
    }
};