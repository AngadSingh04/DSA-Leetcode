class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> vc(26,0);

        for(int i = 0; i<sentence.size(); i++){
            int a = sentence[i] - 'a';
            if(vc[a] != 1){
                vc[a] = 1;
            }
        }

        for(int i = 0; i < vc.size(); i++){
            if(vc[i] == 0){
                return false;
            }
        }
        return true;
    }
};