class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        for(int i = 0; i <arr.size(); i++){
            um[arr[i]]++;
        }
        vector<int> counts;
        for(auto num : um){
            counts.push_back(num.second);
        }
        for(int i = 0; i < counts.size(); i++){
            for(int j = i+1; j < counts.size(); j++){
                if(counts[i]==counts[j]){
                    return false;
                }
            }
        }
        return true;
    }
};