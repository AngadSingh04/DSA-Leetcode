class Solution {
public:
    void bfs(int row, int cols, vector<vector<int>>& vs, vector<vector<char>>& grid){
        vs[row][cols] = 1;
        queue<pair<int,int>> q;
        q.push({row,cols});
        int n = grid.size();
        int m = grid[0].size();


        while(!q.empty()){
            int row = q.front().first;
            int cols = q.front().second;
            q.pop();

            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

            for(int d = 0; d < 4 ; d++){
                    // if(d == 0 && d == 0){
                    //     continue;
                    // }
                    int rowN = row+dr[d];
                    int colN = cols+dc[d];

                    if(rowN >= 0 && rowN < n && colN >= 0 && colN < m && grid[rowN][colN] == '1' && vs[rowN][colN] == 0){
                        vs[rowN][colN] = 1;
                        q.push({rowN,colN});
                    }

            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> vs(row, vector<int>(cols,0));
        int count = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < cols; j++){
                if(vs[i][j] == 0 && grid[i][j] == '1'){
                    bfs(i,j,vs,grid);
                    count++;
                }
            }
        }

        return count;
    }
};