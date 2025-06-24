class Solution {
public:
    bool halvesAreAlike(string s) {
        int countL = 0;
        int countR = 0;
        

        for(int i = 0; i < s.size()/2; i++){
            if( s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                countL++;
            }
        }

        for(int i = s.size()/2; i < s.size(); i++){
            if( s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                countR++;
            }
        }

        return countL==countR;


    }
};