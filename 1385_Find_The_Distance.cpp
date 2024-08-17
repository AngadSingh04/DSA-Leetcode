class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int i = 0;
        int j = 0;
        int count = 0;
        while(i < arr1.size()){
           if(abs(arr1[i]-arr2[j]) <= d){
            count++;
            i++;
            j=0;
           }else{
            j++;
           }
           if(j==arr2.size()){
            i++;
            j = 0;
           }
        }
        return arr1.size()-count;
    }
};