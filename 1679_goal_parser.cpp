class Solution {
public:
    string interpret(string command) {
        string str = "";
        for(int i = 0; i < command.length() - 1; i++){
            if(command[i] == 'G'){
                str += "G";
            }else if(command[i] == '(' && command[i+1] == ')'){
                str+= "o";
                i++;
            }else if(command[i] == '(' && command[i+1] == 'a'){
                str += "al";
                i+=3;
            }
        }
        if(command[command.length()-1] == 'G'){
            str += "G";
        }
        return str;
    }
};