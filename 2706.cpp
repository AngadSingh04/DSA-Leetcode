class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int sm = INT_MAX;
        int ssm = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < sm){
                ssm = sm;
                sm = prices[i];
            }else{
                ssm = min(ssm,prices[i]);
            }
        }
        if(money - (ssm+sm) < 0){
            return money;
        }else{
            return money - (ssm+sm);
        }
    }
};