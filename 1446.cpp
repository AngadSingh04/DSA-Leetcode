class Solution {
    public:
        int maxPower(string s) {
            if(s.length() == 1){
                return 1;
            }
            int ans = 0;
            int x = 1;
            for(int i = 1; i < s.length(); i++){
                if(s[i] == s[i-1]){
                    x++;
                }else{
                    ans = max(ans,x);
                    x = 1;
                }
            }
            ans = max(ans,x);
            return ans;
        }
    };