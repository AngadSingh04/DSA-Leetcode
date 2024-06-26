class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> answer;
        for(int i = 0; i < l.size(); i++){
            vector<int> arr(nums.begin()+l[i], nums.begin()+r[i] + 1);
            sort(arr.begin(),arr.end());
            int diff = arr[1] - arr[0];
            bool istrue = true;
            for(int j = 2; j < arr.size(); j++){
                if(arr[j]-arr[j-1]!=diff){
                    istrue = false;
                    break;
                }
            }
            answer.push_back(istrue);
        }
        return answer;
    }
};