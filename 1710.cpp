class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const auto& a, const auto& b){
            return a[1] > b[1];
        });

        int units = 0;
        for(const auto& p : boxTypes){
            if(p[0] <= truckSize){
                units += p[0] * p[1];
                truckSize = truckSize - p[0];
            }else{
                units += (truckSize * p[1]);
                break;
            }
        }

        return units;

    }
};