class Solution {
    public:
        bool same(vector<int> a, vector<int> b){
            for(int i = 0; i < a.size(); i++){
                if(a[i]!=b[i]){
                    return false;
                }
            }
            return true;
        }
        bool checkInclusion(string s1, string s2) {
            vector<int> a(26);
            for(int i = 0; i < s1.length(); i++){
                int number1 = s1[i] - 'a';
                a[number1]++;
            }
    
            int i = 0;
            int j = s1.length();
            vector<int> b(26);
            while(i < j && i < s2.length()){
                int number2 = s2[i] - 'a';
                b[number2]++;
                i++;
            }
    
            if(same(a,b)){
                return true;
            }
    
            while(i < s2.length()){
                int newN = s2[i] - 'a';
                b[newN]++;
    
                int oldN = s2[i-j] - 'a';
                b[oldN]--;
    
                if(same(a,b)){
                    return true;
                }
                i++;
            }
            return false;
        }
    };