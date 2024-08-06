#include<iostream>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        string str = "";
        int countL = 0;
        int countR = 0;
        for(int i = 0; i < moves.length(); i++){
            if(moves[i] == 'L'){
                countL += 1;
            }else if(moves[i]=='R'){
                countR += 1;
            }
        }
        char ch = '0';
        if(countL == 0 && countR == 0){
            ch ='R';
        }
        if(countL > countR){
            ch = 'L';
        }else if(countR > countL){
            ch = 'R';
        }else{
            ch = 'R';
        }
        int ans = 0;
        for(int i = 0; i < moves.length(); i++){
            if(moves[i]=='_'){
                moves[i] = ch;
            }
        }
        
        for(int i = 0; i < moves.length(); i++){
            if(moves[i] == 'L'){
                ans += -1;
            }else{
                ans += 1;
            }
        }
        if(ans<0){
            ans= -ans;
        }
        return ans;
    }
};

int main(){
    Solution s;
    string a = "_R__LL_";
    int ans = s.furthestDistanceFromOrigin(a);
    cout << ans << endl;
    return 0;
}