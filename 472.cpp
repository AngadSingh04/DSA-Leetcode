class Solution {
public:
    unordered_map<string,bool> um;
    bool isConcatenated(string wrd, unordered_set<string>& us){
        int l = wrd.size();
        if(um.find(wrd) != um.end()){
            return um[wrd];
        }

        for(int i = 0; i < l; i++){
            string prefix = wrd.substr(0,i+1);
            string suffix = wrd.substr(i+1);

            if(us.find(prefix) != us.end() && isConcatenated(suffix,us) ||
            us.find(prefix) != us.end() && us.find(suffix) != us.end()){
                return um[wrd] = true;
            }
        }

        return um[wrd]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        unordered_set<string> us(words.begin(),words.end());
        vector<string> result;

        for(int i =0; i< words.size(); i++){
            string wrd = words[i];

            if(isConcatenated(wrd, us)){
                result.push_back(wrd);
            }
        }

        return result;

    }
};