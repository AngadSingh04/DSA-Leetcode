class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        while( numBottles >= numExchange){
            int a = numBottles / numExchange;
            int b = numBottles % numExchange;
            numBottles = a + b;
            result += a;
        }
        return result;
    }
};