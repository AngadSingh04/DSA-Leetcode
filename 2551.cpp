class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n=weights.size();
            vector<int> auxi; // 
    
            for(int i=0;i<n-1;i++){
                auxi.push_back(weights[i] + weights[i+1]);
            }
            
            sort(auxi.begin(), auxi.end());
            long long minm=0,maxm=0;
    
            for(int i=0;i<k-1;i++){
                minm = minm + auxi[i];
            }
    
            for(int i=n-2;i>=n-k;i--){
                maxm= maxm+ auxi[i];
            }
            return maxm-minm;
        }
    };