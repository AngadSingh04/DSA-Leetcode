class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> um1;
        unordered_map<char,char> um2;

        for(int i = 0; i < s.length(); i++){
            char sc = s[i];
            char tc = t[i];

            if(um1.find(sc) != um1.end() && um1[sc] != tc ||
               um2.find(tc) != um2.end() && um2[tc] != sc){
                return false;
               }

               um1[sc] = tc;
               um2[tc] = sc;
        }

        return true;
        
    }
};