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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> um;
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string tmp = accounts[i][j];
                if(um.find(tmp) == um.end()){
                    um[tmp] = i;
                }else{
                    ds.unionBySize(i,um[tmp]);
                }
            }
        }
        
        vector<vector<string>> str(n);
        for(const auto& p: um){
            string s = p.first;
            int node = ds.findUp(p.second);
            str[node].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(str[i].size() == 0){
                continue;
            }
            vector<string> tmp;
            tmp.push_back(accounts[i][0]);
            sort(str[i].begin(),str[i].end());
            for(const auto& p: str[i]){
                tmp.push_back(p);
            }
            
            ans.push_back(tmp);
            
        }
        
        return ans;
    }
};