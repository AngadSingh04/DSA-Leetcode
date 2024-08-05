class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> um;
        vector<vector<int>> ans;
        for(int i = 0; i < groupSizes.size(); i++){
            int size = groupSizes[i];
            um[size].push_back(i);
            if(um[size].size()==size){
                ans.push_back(um[size]);
                um[size].clear();
            }
        } 
        return ans;
    }
};