class Solution {
public:
    bool selfD(int x){
        if(x < 10){
            return true;
        }
        int a = x;
        if(x >= 10){
            while(x > 0){
                int rem = x%10;
                if(rem==0 || a%rem!=0){
                    return false;
                }
                x = x/10;
            }
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <=right; i++){
            if(selfD(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};