class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for(int i = 0; i < prices.size(); i++){
            int n = prices[i];
            bool isthere = false;
            for(int j = i+1; j < prices.size(); j++){
                if(prices[i]>=prices[j]){
                    int a = n - prices[j];
                    ans.push_back(a);
                    isthere = true;
                    break;
                }
            }
            if(!isthere){
                    ans.push_back(n);
                }
        }
        return ans;
    }
};