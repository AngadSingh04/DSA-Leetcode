class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long i = 0;
        long sum = 0;
        for(int i = 0; i < chalk.size(); i++){
            sum += chalk[i];
        }
        k = k % sum;
        int n = chalk.size() - 1;
        long diff = k;
        while(diff >= chalk[i]){
            diff = diff - chalk[i];
            if(i == n){
                i = 0;
            }else{
                i++;
            }
        }
        return i;
    }
};