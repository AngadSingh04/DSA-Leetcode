class Solution {
public:
    string getEncryptedString(string s, int k) {
        string a =  s + s;
        int ss = s.length();
        k = k%ss;
        for(int i = 0; i < ss; i++){
            s[i] = a[i+k];
        }
        return s;
    }
};