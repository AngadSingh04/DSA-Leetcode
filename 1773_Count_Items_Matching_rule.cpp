class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for(int i = 0; i < items.size(); i++){
            vector<string> a = items[i];
            if(ruleKey == "type" && a[0] == ruleValue){
                count++;
            }else if(ruleKey == "color" && a[1] == ruleValue){
                count++;
            }else if(ruleKey == "name" && a[2] == ruleValue){
                count++;
            }
        }
        return count;
    }
};