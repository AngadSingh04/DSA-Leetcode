class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> count(n,0);
        for(int i = 0; i < roads.size(); i++){
            count[roads[i][0]]++;
            count[roads[i][1]]++;
        }
        sort(count.begin(),count.end());
        long long ans = 0;
        int c = count.size() - 1;
        int k = 0;
        while(n > 0){
            ans += n * count[c - k];
            n--;
            k++;
        }
        return ans;
    }
};