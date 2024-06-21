class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int a = arr.size();
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++){
                if(arr[i] == 2* arr[j] && i!=j){
                    return true;
                }
            }
        }
        return false;
    }
};