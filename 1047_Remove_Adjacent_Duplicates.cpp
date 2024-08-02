#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        // stack<char> a;
        // for(char c: s){
        //     if(!a.empty() && c == a.top()){
        //         a.pop();
        //     }else{
        //         a.push(c);
        //     }
        // }
        // string ans = "";
        // while(!a.empty()){
        //     ans = a.top() + ans;
        //     a.pop();
        // }
        // return ans;
        int i = 0;
        while(i < s.length()){
            if(ans.empty() || ans.back() != s[i]){
                ans.push_back(s[i]);
            }else{
                ans.pop_back();
            }
            i++;
        }
        return ans;
    }
};
int main(){
    Solution s;
    string a = "aaabbbccc";
    string ans = s.removeDuplicates(a);
    cout << ans<<endl;
    return 0;
}