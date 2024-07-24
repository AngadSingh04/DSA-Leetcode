class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return true;
        }else{
            return false;
        }
    }
    string sortVowels(string s) {
        vector<int> v;
        for(int i = 0; i < s.length(); i++){709
            if(isVowel(s[i])){
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(isVowel(s[i])){
                s[i] = v[cnt];
                cnt++;
            }
        }
        return s;
    }
};