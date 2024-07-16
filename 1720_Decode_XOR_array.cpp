class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        int xr = 0;
        for(int i = 0; i < encoded.size(); i++){
           xr = ans.back()^encoded[i];
           ans.push_back(xr);
        }
        return ans;
    }
};