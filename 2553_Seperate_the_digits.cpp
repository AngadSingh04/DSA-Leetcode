class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int n : nums){
            vector<int> a;
            if(n >= 10){
                while(n>0){
                    int rem = n%10;
                    a.push_back(rem);
                    n = n/10;
                }
                reverse(a.begin(),a.end());
                ans.insert(ans.end(),a.begin(),a.end());

            }else{
                ans.push_back(n);
            }
        }
        return ans;
    }
};