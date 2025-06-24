class Solution {
public:
    string intToRoman(int num) {
        vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result ="";
        while(num > 0){
            for(int i = 0; i < val.size(); i++){
                if(num >= val[i]){
                    int times = num/val[i];
                    num = num - (times*val[i]);
                    for(int j = 0; j < times; j++){
                        result += sym[i];
                    }
                    break;
                }
            }
        }
        return result;
    }
};