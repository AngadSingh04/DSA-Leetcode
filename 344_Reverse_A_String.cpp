class Solution {
public:
    void reverseString(vector<char>& s) {
        string k ="";
        for(int i=s.size()-1; i>=0;i--){
            k+=s[i];
        }
        
        for(int i = 0; i<s.size();i++){
            s[i] = k[i];
        }

        for(int i = 0; i<s.size();i++){
            cout<<s[i];
        }
    }
};