class Solution {
public:

    void dfss(int r, int c, vector<vector<int>>& vs, vector<vector<int>>& grid){
        vs[r][c] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i = 0; i < 4; i++){
            int rowN = r + dr[i];
            int colN = c + dc[i];

            if(rowN >= 0 && rowN < n && colN >= 0 && colN < m && vs[rowN][colN] == 0 && grid[rowN][colN] == 1){
                vs[rowN][colN] = 1;
                dfss(rowN,colN, vs,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vs(n, vector<int>(m,0));

        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1 && vs[0][i] == 0){
                dfss(0,i,vs,grid);
            }
        }

        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1 && vs[i][0] == 0){
                dfss(i,0,vs,grid);
            }
        }

        for(int i = 0; i < m; i++){
            if(grid[n-1][i] == 1 && vs[n-1][i] == 0){
                dfss(n-1,i,vs,grid);
            }
        }

        for(int i = 0; i < n; i++){
            if(grid[i][m-1] == 1  && vs[i][m-1] == 0){
                dfss(i,m-1,vs,grid);
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vs[i][j] != 1 && grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};