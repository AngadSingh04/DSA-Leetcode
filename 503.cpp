class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        int n = nums.size();
        //n = 3 
        // [1,2,1, 1,2,1] n = 2*n - 1
        unordered_map<int,int> um;

        for(int i = 2*n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(st.empty()){
                um[i%n] = -1;
            }else{
                um[i%n] = st.top();
            }

            st.push(nums[i%n]);
        }

        for(int i = 0; i < n; i++){
            ans.push_back(um[i]);
        }
        return ans;

    }
};