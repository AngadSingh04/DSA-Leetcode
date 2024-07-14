class Solution {
public:
    string getSmallestString(string s) {
        int a = s.length();
        for(int i = 0; i < a - 1; i++){
            if((s[i] - '0')%2 == (s[i+1] - '0')%2){
                string t = s;
                swap(t[i],t[i+1]);
                if(t < s){
                    return t;
                }  
            }
        }
        return s;

    }
};