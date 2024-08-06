class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> um;
        for(int i = 0; i < arr1.size(); i++){
            um[arr1[i]]++;
        }
        vector<int> ans;
        for(int i = 0; i < arr2.size(); i++){
            if(um.find(arr2[i])!=um.end()){
                int size = um[arr2[i]];
                for(int j =0; j <size; j++){
                    ans.push_back(arr2[i]);
                }
                um.erase(arr2[i]);
            }
        }
        vector<int> temp;
        for(int i = 0; i < arr1.size(); i++){
            if(um.find(arr1[i])!=um.end()){
                temp.push_back(arr1[i]);
                um[arr1[i]]--;
            }
            if(um[arr1[i]]==0){
                um.erase(arr1[i]);
            }
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i < temp.size(); i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};