class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> um;
        char result = '\0';

        for(int i = 0; i < t.size(); i++){
            um[t[i]]++;
        }
        for(int i = 0; i < s.size(); i++){
            um[s[i]]--;
        }

        for(const auto& p : um){
            if(p.second == 1){
                result = p.first;
                break;
            }
        }
        return result;
    }
};