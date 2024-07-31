class Solution {
public:
    int getLucky(string s, int k) {
        string ss = "";
        for(int i = 0; i < s.length(); i++){
            int a = s[i] - 'a' +1;
            string str = to_string(a);
            ss += str;
        }
        while(k--){
            int sum = 0;
            for(char c: ss){
                sum += c - '0';
            }
            ss = to_string(sum);
        }
        int sum = stoi(ss);
        return sum;
    }
};