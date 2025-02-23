class Solution {
    public:
        bool isValid(string s) {
            stack<char> mystack;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                    mystack.push(s[i]);
                }else{
                    
                    if(mystack.empty() || 
                    s[i]==')' && mystack.top() != '(' ||
                    s[i]==']' && mystack.top() != '[' ||
                    s[i]=='}' && mystack.top() != '{'){
                        return false;
                    }
                    mystack.pop();
                }
            }
            if(mystack.empty()){
                return true;
            }
            return false;
        }
    };