// first way
class Solution {
public:
    int minimumSum(int num) {
        vector<int> a;
        while(num > 0){
            int rem = num%10;
            a.push_back(rem);
            num = num/10;
        }
        sort(a.begin(),a.end());
        string a0 = to_string(a[0]);
        string a3 = to_string(a[3]); 
        string fp=a0+a3;
        int ifp = stoi(fp);
        string a1 = to_string(a[1]);
        string a2 = to_string(a[2]); 
        string sp = a1 + a2; 
        int isp = stoi(sp);
        return isp+ifp;
    }
};

// second way
class Solution {
public:
    int minimumSum(int num) {
        vector<int> a;
        while(num > 0){
            int rem = num%10;
            a.push_back(rem);
            num = num/10;
        }
        sort(a.begin(),a.end());

        int num1 = a[0]*10 + a[3];
        int num2 = a[1]*10 + a[2];
        return num1+num2;

         }
};