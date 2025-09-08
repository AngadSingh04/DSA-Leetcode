class Solution {
public:
    int getMax(int ind, int buy, int n, vector<int>& prices, vector<int>& front, vector<int>& curr){
        front[0] = 0;
        front[1] = 0;

        for(int i = n-1; i >= 0 ; i--){
            for(int j = 0; j <= 1; j++){
                int ans = 0;
                if(j){
                    ans = max(-prices[i] + front[0], front[1]);
                }else{
                    ans = max(prices[i] + front[1], front[0]);
                }

                curr[j] = ans;
            }
            front = curr;
        }

        return front[1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<int> front(2,0), curr(2,0);

        return getMax(0,buy,n,prices,front, curr);
    }
};