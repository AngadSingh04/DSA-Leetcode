//did it in on first try :)
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
    
            int rowS = matrix.size();
            int colS = matrix[0].size();
            int totalC = rowS*colS;
            int count = 0;
    
            int startRow = 0;
            int startCol = 0;
            int endRow = rowS-1;
            int endCol = colS-1;
            while(count < totalC){
                //pehle startign row (startcol --> endcol)
                for(int i = startCol; i <= endCol && count < totalC ; i++){
                    ans.push_back(matrix[startRow][i]);
                    count++;
                }
                startRow++;
    
                //ab ending column ( startrow --> endrow)
                for(int i = startRow; i <= endRow && count < totalC; i++){
                    ans.push_back(matrix[i][endCol]);
                    count++;
                }
                endCol--;
    
                //ab ending row (endcol --> statcol)
                for(int i = endCol; i >= startCol && count < totalC; i--){
                    ans.push_back(matrix[endRow][i]);
                    count++;
                }
                endRow--;
    
                //ab starting column ( ening row --> startrow)
                for(int i = endRow; i >= startRow && count < totalC; i--){
                    ans.push_back(matrix[i][startCol]);
                    count++;
                }
                startCol++;
            }
            return ans;
        }
    };