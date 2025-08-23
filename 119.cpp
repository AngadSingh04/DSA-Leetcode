class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> vc;
        vc.push_back(ans);
        for(int i = 1; i < rowIndex + 1; i++){
            ans = ans * (rowIndex + 1 - i);
            ans = ans / (i);
            vc.push_back(ans);
        }

        return vc;
    }
};