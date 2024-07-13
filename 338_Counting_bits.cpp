class Solution {
public:
    vector<int> countBits(int n) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int>ans;
        for(int i = 0; i <=n; i++){
            int count = 0;
            string a = bitset<64>(i).to_string();
            for(int j = 0; j < a.length(); j++){
                if(a[j] == '1'){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};