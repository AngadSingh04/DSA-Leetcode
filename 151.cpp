class Solution {
public:
    string rev(string s){
        string ans = "";
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                temp += ' ';
                ans = temp + ans;
                temp = "";
            }else{
                temp += s[i];
            }
        }
        temp += ' ';
        ans = temp + ans;
        return ans.substr(0,ans.size()-1);
    }
    string reverseWords(string s) {
        int i = 0;
        int j = s.size();
        string result = "";

        while(i < j){
            
            while(i < j && s[i] == ' '){
                i++;
            }

            if(i >= j){
                break;
            }

            if(!result.empty()){
                result += ' ';
            }

            while(i < j && s[i] != ' '){
                result += s[i];
                i++;
            }
        }

        string ans = rev(result);
        return ans;
    }
};