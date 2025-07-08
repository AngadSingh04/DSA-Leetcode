class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> vp(127,{0,0});

        for(int i = 0; i < s.size(); i++){
            vp[s[i]].first = s[i];
            vp[s[i]].second++;
        }

        sort(vp.begin(),vp.end(), [&](const auto& a, const auto& b){
            return a.second > b.second;
        });
        string ans = "";
        for(int i = 0; i < vp.size(); i++){
            if(vp[i].second > 0){
                ans += string(vp[i].second, vp[i].first);
            }
        }

        return ans;

    }
};