class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row_min = grid.size();
        int cols_min = grid[0].size();
        int row_max = INT_MIN;
        int cols_max = INT_MIN;
        int a = grid.size();
        int b = grid[0].size();
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                if(grid[i][j] == 1){
                    row_min = min(row_min, i);
                    cols_min = min(cols_min, j);
                    cols_max = max(cols_max, j);
                    row_max = max(row_max, i);
                }
            }
        }
        if(row_min == grid.size() || cols_min == grid[0].size() || row_max == INT_MIN || cols_max == INT_MIN){
            return 0;
        }
        int len = row_max - row_min +1;
        int brd = cols_max - cols_min +1;
        return len*brd;
    }
};