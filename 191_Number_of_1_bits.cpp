class Solution {
public:
    int hammingWeight(int n) {
    string s = bitset<64>(n).to_string();  
     int count = 0;
        for(int i = 0; i < s.length();i++){
            if(s[i]=='1'){
                count++;
            }
        }
        return count;
    }
};