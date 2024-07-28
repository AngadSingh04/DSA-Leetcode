class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> dc;
        for(int i = 0; i < paths.size(); i++){
            dc.insert(paths[i][0]);
        }

        for(int i = 0; i < paths.size(); i++){
            string a = paths[i][1];
            if(dc.find(a)==dc.end()){
                return a;
            }
        }
        return "";

    }
};