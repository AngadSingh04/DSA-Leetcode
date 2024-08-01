class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(int i = 0; i < details.size(); i++){
            string a = details[i];
            string str = "";
            for(int j = 11; j <=12; j++){
                str+=a[j];
            }
            int istr = stoi(str);
            if(istr > 60){
                count++;
            }
        }
        return count;
    }
};

// substr method for calculating count

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(int i = 0; i < details.size(); i++){
            string a = details[i];
            int istr = stoi(a.substr(11,2));
            if(istr > 60){
                count++;
            }
        }
        return count;
    }
};