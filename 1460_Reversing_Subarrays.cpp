class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_set<int> un1(target.begin(),target.end());
        for(int i = 0; i < arr.size(); i++){
            if(un1.find(arr[i]) == un1.end()){
                return false;
            }
        }
        sort(target.begin(), target.end());
        sort(arr.begin(),arr.end());
        for(int i = 0; i < target.size(); i++){
            if(target[i]!=arr[i]){
                return false;
            }
        }
        return true;
    }
};