class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> um;
        vector<int> a;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                a.push_back(grid[i][j]);
            }
        }
        vector<int> ans(2,0);
        for(int i = 0; i < a.size(); i++){
            um[a[i]]++;
            if(um[a[i]] == 2){
                ans[0]=a[i];
            }
        }
        sort(a.begin(), a.end());
        int max_element = a[a.size()-1];
        unordered_set<int> us(a.begin(),a.end());
        for(int i = 1; i <= max_element; i++){
            if(us.find(i)==us.end()){
                ans[1] = i;
            }
        }
        if(ans[1] == 0){
            if(us.find(max_element+1)==us.end()){
            ans[1]=max_element+1;
        }
        }
        
        return ans;
    }
};
auto fast_io = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
} ();
