class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for(int i = 0; i < m; i++){
        vector<bool> rows(m+1,false);
        vector<bool> cols(m+1,false);
        for(int j = 0; j < m ; j++){
            if(rows[matrix[i][j]]){
                return false;
            }
            rows[matrix[i][j]] = true;
            if(cols[matrix[j][i]]){
                return false;
            }
            cols[matrix[j][i]] = true;
        }
        }
        
        
        return true;
    }
};