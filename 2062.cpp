class Solution {
public:
    bool isVowel(char word){
        if(word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u'){
            return true;
        }
        return false;
    }
    int countVowelSubstrings(string word) {
        int ans = 0;
        unordered_map<char, int> um;
        for(int i = 0; i < word.size(); i++){
            um.clear();
            for(int j = i; j < word.size(); j++){
                if(isVowel(word[j])){
                    um[word[j]]++;
                }else{
                    break;
                }
                if(um.size() == 5){
                    ans++;
                }
            }
        }
        return ans;

    }
};