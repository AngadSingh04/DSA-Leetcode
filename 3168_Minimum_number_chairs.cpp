class Solution {
public:
    int minimumChairs(string s) {
        int cur_chair = 0;
        int max_chair = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='E'){
                cur_chair++;
            }else{
                cur_chair--;
            }
            max_chair = max(max_chair,cur_chair);
        }
        return max_chair;
    }
};