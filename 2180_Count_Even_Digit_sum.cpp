class Solution {
public:
    bool isEven(int x){
        int ans = 0;
        while(x > 0){
            int rem = x%10;
            ans += rem;
            x = x/10;
        }
        if(ans%2==0){
            return true;
        }
        return false;
    }
    int countEven(int num) {
        int count = 0;
        for(int i = num; i > 0; i--){
            if(i >= 10){
                if(isEven(i)){
                    count++;
                }
            }else{
                if(i%2==0){
                    count++;
                }
            }
        }
        return count;
    }
};