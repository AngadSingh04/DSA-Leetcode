class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        long long sum = 0;
        if(x < y){
            swap(x,y);
            for(int i = 0; i < s.length(); i++){
                if(s[i] == 'a'){
                    s[i] = 'b';
                }else if(s[i] == 'b'){
                    s[i] = 'a';
                }
            }
        }

        stack<char> a1;
        for(int i = 0; i <  s.length(); i++){
            if(!(a1.empty()) && a1.top() == 'a' && s[i] == 'b'){
                a1.pop();
                sum += x;
            }else{
                a1.push(s[i]);
            }
        }

        string b = "";
        while(!(a1.empty())){
            b += a1.top();
            a1.pop();
        }
        string c = "";
        for(int i = b.length()-1; i >= 0; i--){
            c += b[i];
        }
        stack<char> a2;
        for(int i = 0; i < c.length(); i++){
            if(!(a2.empty()) && a2.top() == 'b' && c[i] == 'a'){
                sum += y;
                a2.pop();
            }else{
                a2.push(c[i]);
            }
        }
        return sum;
    }
};