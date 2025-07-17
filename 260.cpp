class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long fxor = 0;
        for(int i = 0; i < nums.size(); i++){
            fxor ^= nums[i];
        }

        int rightBit = (fxor & fxor-1) ^ fxor;
        int b1 = 0;
        int b2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if((rightBit & nums[i]) != 0){
                b1 ^=nums[i];
            }else{
                b2 ^=nums[i];
            }
        }

        vector<int> vc;
        vc.push_back(b1);
        vc.push_back(b2);

        return vc;
    }
};