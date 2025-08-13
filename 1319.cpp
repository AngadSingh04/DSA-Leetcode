class Solution {
    class DisjointSet{
        vector<int> rank,size,parent;
        public:

        DisjointSet(int node){
            rank.resize(node+1, 0);
            size.resize(node+1,1);
            parent.resize(node+1);

            for(int i = 0; i <= node; i++){
                parent[i] = i;
            }
        }

        int findUp(int n){
            if(n == parent[n]){
                return n;
            }
            return parent[n] = findUp(parent[n]);
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
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int c = connections.size();
        if(c < n-1){
            return -1;
        }

        for(const auto& p: connections){
            int u = p[0];
            int v = p[1];
            ds.unionBySize(u,v);
        }

        int count = -1;
        for(int i = 0; i < n; i++){
            if(i == ds.findUp(i)){
                count++;
            }
        }

        return count;
    }
};