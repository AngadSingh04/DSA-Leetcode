class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int la = 0;
        int sla = 0;
        int sm = INT_MAX;
        int ssm = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > la){
                sla = la;
                la = nums[i];
            }else{
                sla = max(sla,nums[i]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < sm){
                ssm = sm;
                sm = nums[i];
            }else{
                ssm = min(ssm,nums[i]);
            }
        }

        return (la*sla)-(sm*ssm);
    }
};