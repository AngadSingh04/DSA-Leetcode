class Solution {
public:
    string convertDateToBinary(string date) {
        string ans="";
        string curr = "";
        for(int i =0; i < date.length(); i++){
            if(date[i]!='-'){
                curr += date[i];
            }else{
                int a = stoi(curr);
                string s = bitset<16> (a).to_string();
                s = s.substr(s.find('1'));
                ans += s;
                ans += '-';
                curr = "";
            }
        }
        if(!curr.empty()){
            int a1 = stoi(curr);
            string s1 = bitset<16> (a1).to_string();
            s1 = s1.substr(s1.find('1'));
            ans += s1; 
        }

        return ans;
    }
};