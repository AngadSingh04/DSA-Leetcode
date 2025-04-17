class Solution {
    public:
        bool isAnagram(string s, string t) {
            unordered_map<char,int> um;
            if(s.length()!=t.length()){
                return false;
            }
            for(int i = 0; i < s.size(); i++){
                um[s[i]]++;
            }
    
            for(int i = 0; i < t.size(); i++){
                if(um.find(t[i]) != um.end()){
                    um[t[i]]--;
                }
            }
    
            for(auto &pair: um){
                if(pair.second != 0){
                    return false;
                }
            }
            return true;
        }
    };