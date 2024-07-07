class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        vector<string> fans;
        if(n == 0){
            return ans;
        }
        if(n == 1){
            ans.push_back("1");
            ans.push_back("0");
            return ans;
        }
        ans.push_back("1");
        ans.push_back("0");

        for(int i = 0; i < n-1; i++){
            vector<string> a;
            for(int j = 0; j < ans.size(); j++){
                string s = ans[j];
                a.push_back(s+"1");
                if(s.back() != '0'){
                    a.push_back(s+"0");
                }
            }
            ans = a;
        }
        for(int k = 0; k < ans.size(); k++){
            if(ans[k].size() == n){
                fans.push_back(ans[k]);
            }
        }
        return fans;
    }
};