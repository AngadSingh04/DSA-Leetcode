class Solution {
public:
    void getPar(int n, string s, vector<string>& ans, int o, int c){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(o < n){
            s.push_back('(');
            getPar(n,s,ans,o+1,c);
            s.pop_back();
        }
        if(o > c){
            s.push_back(')');
            getPar(n,s,ans,o,c+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int o = 0;
        int c = 0;

        vector<string> ans;
        string s = "";
        getPar(n, s, ans, o , c);
        return ans;
    }
};