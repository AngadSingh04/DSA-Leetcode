class Solution {
public:
    int numDifferentIntegers(string word) {
        for(int i = 0; i < word.length(); i++){
            if(!isdigit(word[i])){
                word[i] = ' ';
            }
        }
        stringstream ss(word);
        string temp;
        unordered_set<string> ans;
        while(ss >> temp){
           temp.erase(0, temp.find_first_not_of('0'));
           ans.insert(temp);
        }
        return ans.size();
    }
};