class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> a;
        while(n > 0){
            int rem = n%10;
            a.push_back(rem);
            n = n/10;
        }
        vector<int> b;
        for(int i = a.size()-1; i >= 0; i--){
            b.push_back(a[i]);
        }
        int sum = 0;
        for(int i = 0; i < b.size(); i++){
            if(i%2!=0){
                sum += (-b[i]);
            }else{
                sum+= b[i];
            }
        }
        return sum;
    }
};