class Solution {
public:
    bool compare(string& a, string& b){
        if(a.size() != b.size() + 1) return false;
        int aS = 0;
        int bS = 0;
        // bcad
        // cba
        while(aS < a.size()){
            if(a[aS] == b[bS]){
                aS++;
                bS++;
            }else{
                aS++;
            }
        }

        if(aS == a.size() && bS == b.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const auto& a, const auto& b){
            return a.size() < b.size();
        });
        vector<int> dp(n, 1);
        // vector<int> tmp(n);
        // for(int i = 0; i < n; i++) tmp[i] = i;

        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(compare(words[i], words[j]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(dp[i], maxi);
        }

        return maxi;
    }
};