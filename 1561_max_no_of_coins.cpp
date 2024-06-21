class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int chance = piles.size()/3;
        int sum = 0;
        for(int i = chance; i < piles.size(); i = i + 2){
            sum += piles[i];
        }
        return sum;
    }
};