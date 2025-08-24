class Solution {
public:
    int bfss(queue<pair<pair<int,int>,int>>& q, vector<vector<int>>& grid, int count){

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int cnt = q.front().second;
            q.pop();

            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

            for(int i = 0; i < 4; i++){
                int rowN = r + dr[i];
                int colN = c + dc[i];

                if(rowN >= 0 && rowN < n && colN >= 0 && colN < m && grid[rowN][colN] == 1){
                    grid[rowN][colN] = 2;
                    // vc[rowN][colN] = 1;
                    q.push({{rowN,colN}, cnt+1});
                    count = cnt+1;
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

        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();


        bool isPresent = false;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    isPresent = true;
                }
            }
        }
        
        if(!isPresent){
            return 0;
        }

        // vector<vector<int>> vc(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    // vc[i][j] = 1;
                }
            }
        }
        int count = 0;
        int ans = bfss(q, grid, count);

        return ans;
    }
};