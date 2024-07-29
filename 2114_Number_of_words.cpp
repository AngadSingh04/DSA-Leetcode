class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_curr = 0;
        for(int i = 0; i < sentences.size(); i++){
            string a = sentences[i];
            int curr = 1;
            for(int j = 0; j < a.length(); j++){
                if(a[j]==' '){
                    curr++;
                }
            }
            if(curr > max_curr){
                max_curr = curr;
            }
            
        }
        return max_curr;
    }
};