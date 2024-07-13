class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            string a = bitset<32>(i).to_string();
            int count = 0;
            for(int j = 0; j < a.length(); j++){
                if(a[j] == '1'){
                    count++;
                }
            }
            if(count == k){
                sum += nums[i];
            }
        }
        return sum;
    }
};