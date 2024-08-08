class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>> matrix){
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix[i].size(); j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int cols = matrix.size();
        int swapCols = cols/2;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < swapCols; j++){
                swap(matrix[i][j], matrix[i][cols-j-1]);
            }
        }
        return matrix;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++){
            if(mat == target){
                return true;
            }else{
                mat = rotate(mat);
            }
        }
        return false;
    }
};