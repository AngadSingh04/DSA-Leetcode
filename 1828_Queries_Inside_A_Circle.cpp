class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        for(int i = 0; i < queries.size(); i++){
            for(int j = 0; j < points.size(); j++){
                int x = (queries[i][0] - points[j][0])*(queries[i][0] - points[j][0]);
                int y = (queries[i][1] - points[j][1])*(queries[i][1] - points[j][1]);
                if(queries[i][2]*queries[i][2] >= x+y){
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};