class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i = 2; i < num.size(); i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                ans = max(num.substr(i-2,3),ans);
            }
        }
        return ans;
    }
};