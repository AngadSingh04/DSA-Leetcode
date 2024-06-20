class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        int a = 0;
        for(int i = 0; i < n.length(); i++){
            a = n[i] - '0';
            if(a > max){
                max = a;
            }
        }
        return max;
    }
};