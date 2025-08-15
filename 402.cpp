class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;
        // 1,
        for(int i = 0; i < n; i++){
            int a = num[i] - '0';
            while(!st.empty() && k > 0 && st.top() > a){
                st.pop();
                k--;
            }
            st.push(a);
        }

        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
        // if(st.empty()){
        //     return "0";
        // }
        string ans = "";
        while(!st.empty()){
            string a = to_string(st.top());
            ans += a;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while( i < ans.size() && ans[i] == '0'){
            i++;
        }

        string fans = ans.substr(i,ans.size());
        return fans.size() == 0 ? "0": fans;
    }
};