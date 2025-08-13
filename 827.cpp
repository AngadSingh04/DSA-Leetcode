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
        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }

    int getSize(int u){
        return size[findUp(u)];
    }
}; 
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int> vis(n*n, 0);
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                int node = (r*n) + c;
                if(grid[r][c] == 1){
                    int dr[] = {-1,1,0,0};
                    int dc[] = {0,0,-1,1};

                    for(int i = 0; i < 4; i++){
                        int rowN = r + dr[i];
                        int colN = c + dc[i];
                        int tmp = (rowN*n) + colN;

                        if(rowN >= 0 && rowN < n && colN >= 0 && colN < n && grid[rowN][colN] == 1){
                            ds.unionBySize(node,tmp);
                        }
                    }
                }
            }
        }
        int maxCount = INT_MIN;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                int node = (r*n) + c;

                if(grid[r][c] == 0){
                    int dr[] = {-1,1,0,0};
                    int dc[] = {0,0,-1,1};
                    set<int> st;
                    int count = 0;
                    for(int i = 0; i < 4; i++){
                        int rowN = r + dr[i];
                        int colN = c + dc[i];
                        int tmp = (rowN * n) + colN;

                        if(rowN >= 0 && rowN < n && colN >= 0 && colN < n && grid[rowN][colN] == 1){
                        int up_tmp = ds.findUp(tmp);
                        st.insert(up_tmp);

                    }
                }

                for(const auto& l: st){
                    count += ds.getSize(l);
                }
                count += 1;

                if(count > maxCount){
                    maxCount = count;
                }
            }
        }
        }

        if(maxCount == INT_MIN){
            return ds.getSize(0);
        }

        return maxCount;

    }
};