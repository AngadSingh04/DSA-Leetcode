class Solution {
public:
    unordered_map<char,int> um;
    bool cFreq(string s, string goal){
        for(int i = 0; i < s.size(); i++){
            um[s[i]]++;
        }
        for(const auto& p: um){
            if(p.second > 1){
                return true;
            }
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        if(s==goal){
            return cFreq(s,goal);
        }
        vector<int> vc;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != goal[i]){
                vc.push_back(i);
            }
        }

        if(vc.size() != 2){
            return false;
        }
        swap(s[vc[0]], s[vc[1]]);
        if(s==goal){
            return true;
        }

        return false;
    }
};