class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int val1 = 0;
        int val2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(count1 == 0 && nums[i]!=val2){
                count1 = 1;
                val1 = nums[i];
            }else if(count2 == 0 && nums[i]!=val1){
                count2 = 1;
                val2 = nums[i];
            }else if(nums[i] == val1){
                count1++;
            }else if(nums[i] == val2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        int needed = (int)(nums.size()/3) + 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val1){
                cnt1++;
            }else if(nums[i] == val2){
                cnt2++;
            }
        }

        vector<int> ans;
        if(cnt1 >= needed){
            ans.push_back(val1);
        }
        if(cnt2 >= needed){
            ans.push_back(val2);
        }

        return ans;
    }
};