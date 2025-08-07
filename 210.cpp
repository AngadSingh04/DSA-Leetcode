class Solution {
public:
    void bfss(queue<int>& q, vector<int>& inDeg, vector<vector<int>>& adj, vector<int>& ans){
        
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            
            for(const auto& p: adj[tmp]){
                inDeg[p]--;
                if(inDeg[p]==0){
                    q.push(p);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(const auto& p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        
        
        vector<int> inDeg(numCourses,0);
        
        for(int i = 0; i < numCourses; i++){
            for(const auto& p: adj[i]){
                inDeg[p]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        bfss(q,inDeg,adj,ans);
        if(ans.size()!=numCourses){
            return {};
        }
        return ans;

    }
};