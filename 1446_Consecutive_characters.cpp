class Solution {
public:
    int maxPower(string s) {
        int max_count = 0;
        int curr = 1;
        for(int i =1; i < s.length(); i++){
            if(s[i] == s[i-1]){
                curr++;
                if(curr > max_count){
                    max_count = curr;
                }
            }else{
                curr = 1;
            }
        }
        if(curr > max_count){
            return curr;
        }
        return max_count;
    }
};