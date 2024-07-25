class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<char> a;
        string ans;
        for(int i = 0; i < s.length(); i++){
                a.push_back(s[i]);
        }
        sort(a.rbegin(),a.rend());
        for(int i = 0; i < a.size(); i++){
            if(a[i] != '1'){
                a[i-1] = '0';
                a[a.size()-1] = '1';
                break;
            }
        }
        for(int i = 0; i < a.size(); i++){
            ans += a[i];
        }
        return ans;

    }
};