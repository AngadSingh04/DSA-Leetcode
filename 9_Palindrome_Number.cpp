#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        bool a = true;
        string s = to_string(x);
        int len = s.length();
        for(int i=0; i< len; i++){
            if(s[i]!=s[len-1-i]){
                a = false;
                break;
            }
        }
        if(a){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution s;
    int a = 515;
    // cin >> a;
    cout << s.isPalindrome(a);  
}