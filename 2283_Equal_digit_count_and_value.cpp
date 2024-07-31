class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> um;
        vector<int> vc;
        for(int i = 0; i < num.length();i++){
            if(isdigit(num[i])){
                int a = num[i] - '0';
                vc.push_back(a);
            }
        }
        for(int i = 0; i < vc.size(); i++){
            um[vc[i]]++;
        }
        for(int i = 0; i < vc.size(); i++){
            if(vc[i] != um[i]){
                return false;
            }
        }
        return true;
    }
};