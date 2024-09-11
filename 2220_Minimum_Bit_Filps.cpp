class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s = bitset<64> (start).to_string();
        string g = bitset<64> (goal).to_string();

        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i]!=g[i]){
                count++;
            }
        }
        return count;
    }
};