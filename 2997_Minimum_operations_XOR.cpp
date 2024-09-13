class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xor_a = 0;
        for(int i = 0; i < nums.size(); i++){
           xor_a = xor_a^nums[i];
        }
        string s1 = bitset<64> (xor_a).to_string();
        string s2 = bitset<64> (k).to_string();
        int count = 0;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i]!=s2[i]){
                count++;
            }
        }
        return count;
    }
};