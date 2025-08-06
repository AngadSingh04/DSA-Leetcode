class Solution {
public:
    void dfss(int r, int c, vector<vector<int>>& vs, vector<vector<char>>& board){
        vs[r][c] = 1;
        int n = board.size();
        int m = board[0].size();

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i = 0; i < 4; i++){
            int rowN = r + dr[i];
            int colN = c + dc[i];

            if(rowN >= 0 && rowN < n && colN >= 0 && colN < m && vs[rowN][colN] == 0 && board[rowN][colN] == 'O'){
                vs[rowN][colN] = 1;
                dfss(rowN,colN,vs,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vs(n, vector<int>(m,0));

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O' && vs[0][i] == 0){
                dfss(0,i,vs,board);
            }
        }

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' && vs[i][0] == 0){
                dfss(i,0,vs,board);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[n-1][i] == 'O' && vs[n-1][i] == 0){
                dfss(n-1,i,vs,board);
            }
        }

        for(int i = 0; i < n; i++){
            if(board[i][m-1] == 'O' && vs[i][m-1] == 0){
                dfss(i,m-1,vs,board);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vs[i][j] != 1){
                    board[i][j] = 'X';
                }
            }
        }
    }
};