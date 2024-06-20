class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum = 0;
        int ss = s.length();
        int tt = t.length();
        for(int i = 0; i < ss; i++){
            for(int j = 0; j < tt; j++){
                if(s[i]==t[j]){
                    sum += abs(i - j);
                }
            }
        }
        return sum;
    }
};