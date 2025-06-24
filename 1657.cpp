class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }

        vector<int> vc1(26,0);
        vector<int> vc2(26,0);

        for(int i = 0; i < word1.size(); i++){
            int a = word1[i] - 'a';
            vc1[a]++;
            int b = word2[i] - 'a';
            vc2[a]++;
        }

        for(int i = 0; i < vc1.size(); i++){
            if((vc1[i] != 0 && vc2[i] == 0 ) || vc1[i]==0 && vc2[i]!=0){
                return false;
            }
        }
        sort(vc1.begin(), vc1.end());
        sort(vc2.begin(), vc2.end());

        for(int i = 0; i < vc1.size(); i++){
            if(vc1[i] != vc2[i]){
                return false;
            }
        }

        return true;
    }
};