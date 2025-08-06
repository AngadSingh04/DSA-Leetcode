class Solution {
public:
    int bfss(queue<pair<pair<int,int>,int>>& q, vector<vector<int>>& grid, vector<vector<int>>& vs, int temp){

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tmp = q.front().second;
            q.pop();

            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};
            // int temp = temp+1;
            for(int i = 0; i < 4; i++){
                int rowN = r + dr[i];
                int colN = c + dc[i];

                if(rowN >= 0 && rowN < n && colN >= 0 && colN < m && grid[rowN][colN] == 1){
                    grid[rowN][colN] = 2;
                    q.push({{rowN,colN},tmp+1});
                    temp = tmp;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return temp+1;

    }
    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int cols = grid[0].size();
        int count = 0;

        bool isThere = false;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    isThere = true;
                }
            }
        }

        if(!isThere){
            return 0;
        }

        

        vector<vector<int>> vs(row, vector<int>(cols,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        int ans = bfss(q, grid, vs,0);

        return ans;
        
    }
};