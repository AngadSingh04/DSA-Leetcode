class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> um;
        
        if(s.length() != t.length()){
            return false;
        }

        for(const auto& p: s){
            um[p]++;
        }
        for(const auto& p: t){
            um[p]--;
        }

        for(const auto& p: um){
            if(p.second < 0){
                return false;
            }
        }

        return true;

    }
};