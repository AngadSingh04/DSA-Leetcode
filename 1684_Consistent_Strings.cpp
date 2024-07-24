class Solution {
public:
    bool isAllowed(string s, string a){
        unordered_set<char> allowedS(a.begin(),a.end());
            for(char c: s){
                if(allowedS.find(c) == allowedS.end()){
                    return false;
                }
            }
            return true;
        
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            string str = words[i];
            if(isAllowed(str , allowed)){
                count++;
            }
        }
        return count;
    }
};