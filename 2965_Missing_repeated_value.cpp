class Solution {
    public:
        static vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
    
            int xr = 0;
            int count = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    count++;
                }
            }
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    xr = xr ^ grid[i][j];
                }
            }
            for(int i = 1; i <= count; i++) {
                xr ^= i;
            }
    
            int bitNo = 0;
            while(1){
                if((xr & (1 << bitNo))!=0){
                    break;
                }else{
                    bitNo++;
                }
            }
    
            int zero = 0;
            int one = 0;
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if((grid[i][j] & (1 << bitNo))!=0){
                        one = one^grid[i][j];
                    }else{
                        zero = zero^grid[i][j];
                    }
                }
            }
    
            for(int i = 1; i <= count; i++){
                if((i & (1 << bitNo))!=0){
                    one = one^i;
                }else{
                    zero = zero^i;
                }
            }
            int ans = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == zero){
                        ans++;
                    }
                }
            }
            if(ans==2){
                return {zero,one};
            }else{
                return {one,zero};
            }
    
        }
    };