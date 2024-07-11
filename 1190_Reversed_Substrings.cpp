// My First Stack question :)
// Also 100 questions are done

class Solution {
public:
    string reverseParentheses(string s) {
    stack<char> mystack;
    for(int i = 0; i < s.length(); i++){
        if(s[i]!= ')'){
            mystack.push(s[i]);
        }else{
            string a;
            while(!(mystack.empty()) && mystack.top() != '('){
                a += mystack.top();
                mystack.pop();
            }
            if(!(mystack.empty()) && mystack.top() == '('){
                mystack.pop();
            }
            for(int k = 0; k < a.length(); k++){
            mystack.push(a[k]);
        }
        }
        
    }
    string ans;
    while(!(mystack.empty())){
        ans = mystack.top() + ans;
        mystack.pop();
    }
    
    return ans;
    }
};

