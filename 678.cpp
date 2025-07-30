class Solution {
public:
    // bool checkString(string s, int& ind, int& count){

    // }
    bool checkValidString(string s) {
        
        // int count = 0;
        // int ind = 0;
        // return checkString(s,ind,count);

        // ()()*()
        // min = 0 
        // max = 0

        int size = s.size();
        int min = 0;
        int max = 0;

        for(int i = 0; i < size; i++){
            if(s[i] == '('){
                min++;
                max++;
            }else if(s[i] == ')'){
                min--;
                max--;
            }else{
                min--;
                max++;
            }
            if(min < 0){
                min = 0;
            }
            if(max < 0){
                return false;
            }
            
        }

        //min=0
        //max=2

        if(min == 0 || max == 0){
            return true;
        }
        return false;


    }
};