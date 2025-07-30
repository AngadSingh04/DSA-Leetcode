class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int size = bills.size();
        int change5 = 0;
        int change10 = 0;
        // change5 = 5
        // change10 = 1
        // change20 = 1
        for(int i = 0; i < size; i++){
            if(bills[i] == 5){
                change5++;
            }else if(bills[i] == 10){
                if(change5 >= 1){
                    change5--;
                    change10++;
                }else{
                    return false;
                }
            }else{
                if(change5 >= 1 && change10 >=1){
                    change5--;
                    change10--;
                    
                }else if(change5 >= 3){
                    change5 = change5 - 3;
                }else{
                    return false;
                }
            }

        }
        return true;
    }
};