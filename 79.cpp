class Solution {
public:

    bool find(int i, int j, int ind,vector<vector<char>>& board, string word){
        int n = board.size();
        int m = board[0].size();
        if(ind == word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '-1' || board[i][j] != word[ind]){
            return false;
        }
        int temp = board[i][j];
        board[i][j] = '-1';
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int k = 0; k < 4; k++){
            int iN = i + dr[k];
            int jN = j + dc[k];
            if(find(iN, jN, ind+1, board,word)){
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] && find(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};