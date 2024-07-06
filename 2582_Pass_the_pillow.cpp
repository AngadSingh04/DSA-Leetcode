class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        int direction = 1;
        while(time > 0){
            if(direction == 1){
                i++;
            }else{
                i--;
            }
            if(i == n || i == 1){
                direction = direction * -1;
            }
            time--;
        }
        return i;
    }
};