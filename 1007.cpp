class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int n=tops.size();
            unordered_map<int,int>t;
            unordered_map<int,int>b;
    
            for(int ele:tops){
                t[ele]++;
            }
            for(int ele:bottoms){
                b[ele]++;
            }
    
            int maxf=1,maxele=0,maxil=-1;
            for(auto ele:t){
                if(maxf<=ele.second){
                    maxele=ele.first;
                    maxf=ele.second;
                    maxil=0;
                }
            }
            for(auto ele:b){
                if(maxf<=ele.second){
                    maxele=ele.first;
                    maxf=ele.second;
                    maxil=1;
                }
            }
            int ans=0;
            for(int i=0;i<n;i++){
                if((maxil==0 and tops[i]!=maxele) or (maxil==1 and bottoms[i]!=maxele)) {
                    swap(bottoms[i],tops[i]);
                    ans++;
                }
            }
            if(maxil==0){
                for(int i=0;i<n;i++){
                    if(tops[i]!=maxele) return -1;
                }
            }else{
                for(int i=0;i<n;i++){
                    if(bottoms[i]!=maxele) return -1;
                }
            }
    
           return ans;
    
        }
    };