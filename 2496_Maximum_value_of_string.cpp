class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int max = 0;
        for(int i = 0; i < strs.size(); i++){
            int count = 0;
            string a = strs[i];
            bool b = true;
            for(int j = 0; j < a.length(); j++){
                if(!isdigit(a[j])){
                    b = false;
                    break;
                }
            }
            if(b){
                count = stoi(a);
            }else{
                count = a.length();
            }

            if(count > max){
                max = count;
            }
    }
    return max;
    }
};