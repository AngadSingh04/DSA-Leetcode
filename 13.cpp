class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> um{
            {'M',1000},
            {'D',500},
            {'C',100},
            {'L',50},
            {'X',10},
            {'V',5},
            {'I',1}
        };
        int ans = 0;
        for(int i = s.size()-2; i >= 0; i--){
            if(um[s[i]] >= um[s[i+1]]){
                ans += um[s[i]];
            }else{
                ans -= um[s[i]];
            }
        }
        
        ans += um[s[s.size()-1]];

        return ans;
    }
};