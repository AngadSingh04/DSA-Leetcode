// Not very optimal solution :(

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> index(worker.size(), 0);
        for(int i = 0; i < worker.size(); i++){
            int max = 0;
            for(int j = 0; j < difficulty.size(); j++){
                if(worker[i]>=difficulty[j]){
                    if(profit[j] > max){
                        max = profit[j];
                    }
                }
            }            
            index[i] = max;
  
        }
        int sum = 0;
        for(int i = 0; i < index.size(); i++){
            sum += index[i];
        }
        return sum;
    }
};