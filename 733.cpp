class Solution {
public:

    void bfs(int sr, int sc, vector<vector<int>>& image, int color, vector<vector<int>>& vs){
        vs[sr][sc] = 1;
        int temp = image[sr][sc];

        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});

        image[sr][sc] = color;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

            for(int i = 0; i < 4; i++){
                int rowN = r + dr[i];
                int colN = c + dc[i];

                if(rowN >= 0 && rowN < n && colN >= 0 && colN < m && image[rowN][colN] == temp && vs[rowN][colN] == 0){
                    vs[rowN][colN] = 1;
                    q.push({rowN,colN});
                    image[rowN][colN] = color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vs(n, vector<int>(m,0));

        bfs(sr,sc,image,color,vs);
        return image;
    }
};