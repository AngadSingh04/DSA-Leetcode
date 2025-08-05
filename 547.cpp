class Solution {
public:

    void dfs(int start, vector<vector<int>>& adj, vector<int>& visited){
        visited[start] = 1;

        for(const auto& a: adj[start]){
            if(visited[a] == 0){
                dfs(a,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int c = isConnected.size();
        vector<vector<int>> adj(c+1);
        int count = 0;

        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected.size(); j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        vector<int> visited(c+1,0);

        for(int i = 1; i <= isConnected.size(); i++){
            if(visited[i] == 0){
                dfs(i,adj,visited);
                count++;
            }
        }
        return count;
    }
};