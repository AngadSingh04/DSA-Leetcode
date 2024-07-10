class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> a;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "C"){
                if(!(a.empty())){
                     a.pop_back();
                }  
            }else if(operations[i] == "D"){
                a.push_back(a[a.size()-1]*2);
            }else if(operations[i] == "+"){
                a.push_back(a[a.size()-1]+a[a.size()-2]);
            }else{
                int aa = std::stoi(operations[i]);
                a.push_back(aa);
            }
        }
        int summ = 0;
        for(int i = 0; i < a.size(); i++){
            summ += a[i];
        }
        return summ;
    }
};