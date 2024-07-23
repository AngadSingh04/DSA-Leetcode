class Solution {
public:
    string finalString(string s) {
        
        stack<char> a;
        for(int i = 0; i < s.length(); i++){
            if(s[i]!='i'){
                a.push(s[i]);
            }else{
                string str;
                while(!a.empty()){
                    str += a.top();
                    a.pop();
                }
                if(!a.empty() && s[i] == 'i'){
                    a.pop();
                }
                for(int i = 0; i < str.length(); i++){
                    a.push(str[i]);
                }
            }
        }
        string ans;
        while(!a.empty()){
            ans = a.top() + ans;
            a.pop();
        }
        return ans;
    }
};

// Second way 

class Solution {
public:
    string finalString(string s) {
        string a = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i]!='i'){
                a += s[i];
            }else{
                string b = "";
                for(int j = a.length() - 1; j >=0; j--){
                    b += a[j];
                }
                a = b;
            }
        }
        return a;
    }
};
