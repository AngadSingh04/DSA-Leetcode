class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int count = 0;
        int b = batteryPercentages.size();
        for(int i = 0; i < b; i++){
            if(batteryPercentages[i] > 0){
                count++;
                for(int j = i+1; j < batteryPercentages.size(); j++){
                    batteryPercentages[j] = max(0, batteryPercentages[j]-1);
                }
            }
        }
        return count;
    }
};

//
class Solution{
    public:
        int countTestedDevices(vector<int>& batteryPercentages) {
        int count = 0;
        int b = batteryPercentages.size();
        for(int i = 0; i < b; i++){
            if(batteryPercentages[i] > count){
                count++;
            }
        }
        return count;
    }
};

