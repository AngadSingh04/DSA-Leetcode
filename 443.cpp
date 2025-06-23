class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        int index = 0;

        char curr_char = chars[0];

        for(int i = 1; i < chars.size(); i++){
            if(chars[i] == chars[i-1]){
                count++;
            }else{
                chars[index] = curr_char;
                index++;
                if(count > 1){
                    string as = to_string(count);
                    for(char c: as){
                        chars[index] = c;
                        index++;
                    }
                }
                curr_char = chars[i];
                count = 1;
            }
        }

        chars[index] = curr_char;
        index++;
        if(count> 1){
           string as = to_string(count);
            for(char c: as){
                chars[index] = c;
                index++;
            }
        }


        return index;
    }
};