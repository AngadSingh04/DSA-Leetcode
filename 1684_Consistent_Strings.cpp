class Solution {
public:
    bool isConsistent(string a, string w){
        unordered_set<char> us(a.begin(), a.end());
        for(char c: w){
            if(us.find(c) == us.end()){
                return false;
            }
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            string str = words[i];
            if(isConsistent(allowed, str)){
                count++;
            }
        }
        return count;
    }
};