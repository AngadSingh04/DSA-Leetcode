class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> um;
        for(int i = 0; i < arr.size(); i++){
            um[arr[i]]++;
        }
        vector<string> res;
        for(int i = 0; i < arr.size(); i++){
            if(um[arr[i]]==1){
                res.push_back(arr[i]);
            }
        }
        string ans = "";
        if(k-1 < res.size()){
            ans = res[k-1];
        }
        return ans;
    }
};