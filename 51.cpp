class Solution {
public:
    bool isTrue(int row, int col, vector<string>& vc, int n){
        int i = row;
        int j = col;

        while(row >= 0 && col >= 0){
            if(vc[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        row = i;
        col = j;
        while(col >= 0){
            if(vc[row][col] == 'Q'){
                return false;
            }
            col--;
        }

        col = j;
        while(row < n && col >= 0){
            if(vc[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }

        return true;
    }
    void getSet(int col, vector<vector<string>>& ans, vector<string>& vc, int n){
        if(col == n){
            ans.push_back(vc);
            return;
        }

        for(int i = 0; i < n; i++){
            if(isTrue(i,col,vc,n)){
                vc[i][col] = 'Q';
                getSet(col+1, ans, vc, n);
                vc[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> vc(n,s);
        getSet(0, ans, vc, n);
        return ans; 
    }
};