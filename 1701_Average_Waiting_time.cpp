class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curr = 0;
        int c = customers.size();
        double sum = 0;
        for(int i = 0; i < c; i++){
            int time = 0;
            if(customers[i][0]>curr){
                curr = customers[i][0] + customers[i][1];
                time = curr - customers[i][0];
            
            }else{
                curr = curr + customers[i][1];
                time = curr - customers[i][0];
            }
            sum += time;
        }
        return sum/c;
    }
};