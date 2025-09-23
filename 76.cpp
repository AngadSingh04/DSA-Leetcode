class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> arr(256,0);
        for(int i = 0; i < m; i++){
            arr[t[i]]++;
        }

        int l = 0;
        int r = 0;
        int sIndex = -1;
        int minLen = 1e9;
        int cnt = 0;

        while(r < n){
            if(arr[s[r]] > 0) cnt++;
            arr[s[r]]--;

            while(cnt == m){
                if(r - l + 1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                arr[s[l]]++;
                if(arr[s[l]] > 0){
                    cnt = cnt-1;
                }
                l++;
            }

            r++;
        }

        if(sIndex == -1) return "";
        return s.substr(sIndex, minLen);
    }
};