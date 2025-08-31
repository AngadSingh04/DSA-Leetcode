class Solution {
public:
    void getSet(vector<string>& ans, string vc, vector<string>& st, int ind, string& digits){
        if(ind == digits.size()){
            ans.push_back(vc);
            return;
        }

        int a = digits[ind] - '0';
        string tmp = st[a];

        for(int i = 0; i < tmp.size(); i++){
            vc.push_back(tmp[i]);
            getSet(ans,vc,st,ind+1,digits);
            vc.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> st = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string vc = "";
        int ind = 0;

        getSet(ans,vc,st,ind,digits);

        return ans;
    }
};