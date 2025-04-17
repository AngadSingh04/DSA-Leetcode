class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            vector<string> v;
            stringstream ss(s);
            string t;
            while(ss >> t){
                v.push_back(t);
            }
            if(pattern.length() != v.size()){
                return false;
            }
            unordered_map<char,string> wc;
            unordered_map<string,char> cw;
            for(int i = 0; i < pattern.length(); i++){
                char c = pattern[i];
                string w = v[i];
                if(wc.count(c)){
                    if(wc[c]!=w){
                        return false;
                    }
                }else{
                    wc[c] = w;
                }
    
                if(cw.count(w)){
                    if(cw[w]!=c){
                        return false;
                    }
                }else{
                    cw[w] = c;
                }
            }
    
            return true;
        }
    };