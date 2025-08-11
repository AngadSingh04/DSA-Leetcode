class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n,INT_MAX));

        for(const auto& p: edges){
            dis[p[0]][p[1]] = p[2];
            dis[p[1]][p[0]] = p[2];
        }
        for(int i = 0; i < n; i++){
            dis[i][i] = 0;
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dis[i][k] == INT_MAX || dis[k][j] == INT_MAX){
                        continue;
                    }else{
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }

        int city = 0;
        int mCount = n+1;

        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(dis[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= mCount){
                mCount = count;
                city = i;
            }
        }

        return city;
    }
};