class Solution {
public:
    vector<string> vc;
    bool isValid(string s){
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                   }
                st.pop();
            }
        }
        return st.empty();
    }
    void gPar(string& s, int n){
        if(s.size() == 2*n){
            if(isValid(s)){
                vc.push_back(s);
            }
            return;
        }
        s.push_back('(');
        gPar(s,n);
        s.pop_back();

        s.push_back(')');
        gPar(s,n);
        s.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        gPar(s,n);
        return vc;
    }
};