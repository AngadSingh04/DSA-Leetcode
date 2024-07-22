class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<string> ans;
        unordered_map<int, string> a;
        for(int i = 0; i < n; i++){
            a[heights[i]] = names[i];
        }
        sort(heights.begin(),heights.end());
        reverse(heights.begin(),heights.end());

        for(int i = 0; i < n; i++){
            ans.push_back(a[heights[i]]);
        }
        return ans;
    }
};