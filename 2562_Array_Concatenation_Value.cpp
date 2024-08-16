class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long sum = 0;
        if(nums.size()%2!=0){
            sum += nums[nums.size()/2];
        }
        for(int i = 0; i < nums.size()/2; i++){
            int k = nums[i];
            int j = nums[nums.size()-1-i];
            string a = to_string(k);
            string b = to_string(j);
            string c = a+b;
            int con = stoi(c);
            sum += con;
        }
        return sum;
    }
};