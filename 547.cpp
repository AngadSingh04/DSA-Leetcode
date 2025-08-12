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


class Solution {
    class DisjointSet{
    vector<int> rank, parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUp(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUp(parent[node]);
    }

    void unionByRank(int u, int v){
        int up_u = findUp(u);
        int up_v = findUp(v);

        if(up_u == up_v){
            return;
        }
        if(rank[up_u] < rank[up_v]){
            parent[up_u] = up_v;
        }else if(rank[up_v] < rank[up_u]){
            parent[up_v] = up_u;
        }else{
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }

    void unionBySize(int u, int v){
        int up_u = findUp(u);
        int up_v = findUp(v);
        if(up_u == up_v){
            return;
        }
        if(rank[up_u] < rank[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
}; 
public:

    // void dfs(int start, vector<vector<int>>& adj, vector<int>& visited){
    //     visited[start] = 1;

    //     for(const auto& a: adj[start]){
    //         if(visited[a] == 0){
    //             dfs(a,adj,visited);
    //         }
    //     }
    // }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int c = isConnected.size();
        
    DisjointSet ds(c);

    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            if(isConnected[i][j] == 1){
                ds.unionBySize(i+1,j+1);
            }
        }
    }
    int count = 0;
    for(int i = 1; i <= c; i++){
        if(i == ds.findUp(i)){
            count++;
        }
    }

    return count;

    }
};