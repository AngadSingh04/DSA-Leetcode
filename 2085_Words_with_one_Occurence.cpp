class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> um1;
        unordered_map<string,int> um2;
        for(int i = 0 ; i < words1.size(); i++){
            um1[words1[i]]++;
        }
        for(int j = 0; j < words2.size(); j++){
            um2[words2[j]]++;
        }
        int count = 0;
        for(const auto& pair: um1){
            if(pair.second == 1 && um2[pair.first]==1){
                count++;
            }
        }
        return count;
        
    }
};