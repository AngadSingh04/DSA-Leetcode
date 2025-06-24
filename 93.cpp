class Solution {
public:
    int n;
    vector<string> result;

    bool isValid(string str){
        int val = stoi(str);
        if(str[0] == '0'){
            return false;
        }else if(val > 255){
            return false;
        }
        return true;
    }
    void solve(string &s, int index, int parts, string curr){
        if(n == index && parts == 4){
            curr.pop_back();
            result.push_back(curr);
        }

        if(index+1 <= n){
            solve(s,index+1,parts+1, curr + s.substr(index,1) + ".");
        }
        if(index+2 <=n && isValid(s.substr(index,2))){
            solve(s,index+2,parts+1, curr + s.substr(index,2) + ".");
        }
        if(index+3 <= n && isValid(s.substr(index,3))){
            solve(s,index+3,parts+1, curr + s.substr(index,3) + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(n > 12){
            return result;
        }

        n = s.size();
        int parts = 0;
        string curr = "";
        solve(s, 0, parts, curr);

        return result;
        
    }
};