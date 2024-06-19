class Solution {
public:
    vector<int> evenOddBit(int n) {
        string a = bitset<64>(n).to_string();
        vector<int> answer;
        int count = 0;
        int count1 = 0;
        for(int i = a.length()-1; i >= 0; i--){
            if(a[i] == '1'){
                if(i%2 == 0){
                    count++;
                }else{
                    count1++;
                }
            }
        }
        answer.push_back(count1);
        answer.push_back(count);
        return answer;
    }
};