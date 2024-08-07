class Solution {
public:
    string truncateSentence(string s, int k) {
        vector<string> parts;
        string word;
        istringstream stream(s);
        while(stream >> word){
            parts.push_back(word);
        }
        string ans = "";
        for(int i = 0; i < k; i++){
            if(i == k-1){
                ans+=parts[i];
            }else{
                 ans += parts[i] + " ";
            }
           
        }
    return ans;
    }
};