class Solution {
public:

    int histo(vector<int>& prefix){
        int n = prefix.size();
        int maxi = INT_MIN;
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && prefix[st.top()] > prefix[i]){
                int hIndex = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1: st.top();
                maxi = max(maxi, prefix[hIndex] * (nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int hIndex = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1: st.top();
            maxi = max(maxi, prefix[hIndex] * (nse-pse-1));
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m,0));

        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += 1;
                if(matrix[i][j] == '0'){
                    sum = 0;
                }
                prefix[i][j] = sum;
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, histo(prefix[i]));
        }

        return ans;
    }
};