class Solution {
public:
    int minOperations(string s) {
        int count1 = 0; // 01010101
        int count2 = 0; // 10101010

        for(int i = 0; i < s.size(); i++){
            if(i%2 == 0){
                if(s[i] != '0'){
                    count1++;
                }else{
                    count2++;
                }
            }else{
                if(s[i] != '1'){
                    count1++;
                }else{
                    count2++;
                }
            }
        }

        return min(count1,count2);
    }
};