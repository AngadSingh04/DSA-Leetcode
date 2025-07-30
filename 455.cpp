class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int i = 0;
        int j = 0;
        int count = 0;           // i
        sort(g.begin(),g.end()); // 7,8,9,10
        sort(s.begin(),s.end()); // 5,6,7,8
                                 //     j

        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                count++;
                i++;
                j++;
            }else{
                j++;
            }
        }

        return count;
    }
};