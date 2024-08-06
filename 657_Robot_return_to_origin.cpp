class Solution {
public:
    bool judgeCircle(string moves) {
        int rl = 0;
        int ud = 0;
        for(int i =0; i < moves.length(); i++){
            if(moves[i] == 'L'){
                rl += -1;
            }else if(moves[i] == 'R'){
                rl += 1;
            }else if(moves[i] == 'U'){
                ud += 1;
            }else{
                ud += -1;
            }
        }
        if(rl == 0 && ud == 0){
            return true;
        }
        return false;
    }
};