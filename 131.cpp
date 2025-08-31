class Solution {
public:
    void getSet(vector<vector<string>>& ans, vector<string>& vc, string s, int ind){
        if(ind == s.size()){
            ans.push_back(vc);
            return;
        }

        for(int i = ind; i < s.size(); i++){
            if(isPal(ind, i, s)){
                vc.push_back(s.substr(ind, i - ind + 1));
                getSet(ans, vc, s, i+1);
                vc.pop_back();
            }
        }
    }
    bool isPal(int start, int end, string s){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vc;
        int ind = 0;

        getSet(ans,vc,s,ind);
        return ans;
    }
};