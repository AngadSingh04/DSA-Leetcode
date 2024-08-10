class Solution {
public:
    int largestInteger(int num) {
        vector<int> even;
        vector<int> odd;
        int num1 = num;
        while(num > 0){
            int rem = num %10;
            if(rem%2==0){
                even.push_back(rem);
            }else{
                odd.push_back(rem);
            }
            num = num/10;
        }
        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());
        string str = "";
        while(num1 > 0){
            int rem = num1 %10;
            if(rem%2==0){
                str += to_string(even.back());
                even.pop_back();
            }else{
                str += to_string(odd.back());
                odd.pop_back();
            }
            num1 = num1/10;
        }
        reverse(str.begin(), str.end());
        int ans = stoi(str);
        return ans;
    }
};