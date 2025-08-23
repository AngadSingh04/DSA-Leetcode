class Solution {
public:
    vector<int> genRow(int row){
        long long ans = 1;
        vector<int> vc;
        vc.push_back(ans);

        for(int i = 1; i < row; i++){
            ans = ans * (row - i);
            ans = ans / (i);
            vc.push_back(ans);
        }

        return vc;
    }
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> sol;
        int ele = 1;
        for(int i = 1; i <= numRows; i++){
            vector<int> tmp = genRow(i);
            sol.push_back(tmp);
        }

        return sol;
    }
};