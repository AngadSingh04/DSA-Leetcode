class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0;
        int r = 0;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R'){
                r += 1;
            }else{
                l += 1;
            }
            if(r-l == 0){
                count++;
            }
            
        }
        return count;
    }
};