// Medium level problem :)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                int a = stoi(tokens[i]);
                st.push(a);
            }else if(tokens[i] == "+"){
                int a_add = st.top();
                st.pop();
                int b_add = st.top();
                st.pop();
                st.push(a_add + b_add);
            }else if(tokens[i] == "-"){
                int a_subtract = st.top();
                st.pop();
                int b_subtract = st.top();
                st.pop();
                st.push(b_subtract - a_subtract);
            }else if(tokens[i] == "*"){
                int a_multiply = st.top();
                st.pop();
                int b_multiply = st.top();
                st.pop();
                st.push(a_multiply * b_multiply);
            }else if(tokens[i] == "/"){
                int a_divide = st.top();
                st.pop();
                int b_divide = st.top();
                st.pop();
                st.push(b_divide / a_divide);
            }
        }
        return st.top();
    }
};