class Solution {
public:
    int rev(int x){
        string a = "";
        while(x > 0){
            string rem = to_string(x%10);
            a += rem;
            x /=10;
        }
        int b = stoi(a);
        return b;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> np;
        for(int i = 0; i < n; i++){
            if(np.find(nums[i]-rev(nums[i])) != np.end()){
                count += np[nums[i]-rev(nums[i])];
            }
            np[nums[i]-rev(nums[i])]++;
        }
        return count % 1000000007;
    }
};