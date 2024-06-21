class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<int> a;
        for(int i = 0; i<grumpy.size(); i++){
            if(grumpy[i]==0){
                a.push_back(i);
            }
        }
        int sum =0;
        for(int i =0; i< a.size(); i++){
            sum += customers[a[i]];
        }
        int maxN = 0;
        int cAns = 0;
        for(int i =0;i < minutes; i++){
            if(grumpy[i]==1){
                sum += customers[i];
            }
        }
        maxN = cAns;
        for(int i = minutes; i < customers.size(); i++){
           if(grumpy[i] == 1){
            cAns += customers[i];
           }
           if(grumpy[i-minutes] == 1){
            cAns -= customers[i-minutes];
           }
           if(cAns > maxN){
            maxN = cAns;
           }
        }
        return sum + maxN;
        
    }
};