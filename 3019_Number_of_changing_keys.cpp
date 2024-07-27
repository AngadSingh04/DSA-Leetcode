class Solution {
public:
    int countKeyChanges(string s) {
        for(int i = 0; i < s.length(); i++){
            s[i] = tolower(s[i]);
        }
        int count = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i]!=s[i-1]){
                count++;
            }
        }
        return count;
    }
};