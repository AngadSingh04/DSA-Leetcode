class Solution {
public:
    bool bfss(int start, vector<int>& vs, vector<vector<int>>& graph){
        vs[start] = 0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int a = q.front();
            q.pop();
            
            for(const auto& p: graph[a]){
                if(vs[p] == -1){
                    vs[p] = !vs[a];
                    q.push(p);
                }else if(vs[p] == vs[a]){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // vector<vector<int>> adj(V);
        
        // for(const auto& a: edges){
        //     int u = a[0];
        //     int v = a[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }
        
        vector<int> vs(graph.size(),-1);
        for(int i = 0; i < graph.size(); i++){
            if(vs[i] == -1){
                if(!bfss(i,vs,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};