class Solution {
public:
    int minFlips(int a, int b, int c) {
        int or_ans = a|b;
        string a1 = bitset<64> (a).to_string();
        string b1 = bitset<64> (b).to_string();
        string s1 = bitset<64> (or_ans).to_string();
        string s2 = bitset<64> (c).to_string(); 
        int count = 0;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i]!=s2[i]){
                if(s1[i] == '1' && s2[i] == '0'){
                    if(a1[i]=='1' && b1[i]=='1'){
                        count = count+2;
                    }else{
                        count++;
                    }
                }else{
                    count++;
                }
            }
        }
        return count;
    }
};