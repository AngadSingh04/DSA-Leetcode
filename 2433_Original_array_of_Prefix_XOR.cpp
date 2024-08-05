class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int p = pref.size();
        vector<int> ans(p);
        ans[0]=pref[0];
        int sum = 0;
        for(int i = 1; i < p; i++){
            ans[i] = pref[i]^pref[i-1];
        }
        return ans;
    }
};