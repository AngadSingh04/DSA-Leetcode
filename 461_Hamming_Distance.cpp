class Solution {
public:
    int hammingDistance(int x, int y) {
        int count =0;
        string a = bitset<64>(x).to_string();
        string b = bitset<64>(y).to_string();
        for(int i = 0; i < a.length(); i++){
            if(a[i]!=b[i]){
                count++;
            }
        }
        return count;
    }
};