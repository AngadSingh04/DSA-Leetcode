class Solution {
public:
    int majorityElement(vector<int>& nums) {



        int count = 0;
        int e = 0;

        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                count = 1;
                e = nums[i];
            }else if(nums[i]==e){
                count++;
            }else{
                count--;
            }
        }

        return e;

        // for(int i = 0; i < nums.size(); i++){

        // }




        // unordered_map<int,int> um;
        // int n = nums.size();

        // for(int i = 0; i < nums.size(); i++){
        //     um[nums[i]]++;
        // }

        // for(const auto&p : um){
        //     if(p.second > n/2){
        //         return p.first;
        //     }
        // }
        // return -1;
    }
};