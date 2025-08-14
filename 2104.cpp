class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> psee(n);
        vector<int> nse(n);
        vector<int> pgee(n);
        vector<int> nge(n);

        stack<int> st1;
        stack<int> st2;
        stack<int> st3;
        stack<int> st4;


        for(int i = n-1; i>=0; i--){
            while(!st1.empty() && nums[st1.top()] >= nums[i]){
                st1.pop();
            }
            if(st1.empty()){
                nse[i] = n;
            }else{
                nse[i] = st1.top();
            }

            st1.push(i);
        }

        for(int i = 0; i < n; i++){
            while(!st2.empty() && nums[st2.top()] > nums[i]){
                st2.pop();
            }
            if(st2.empty()){
                psee[i] = -1;
            }else{
                psee[i] = st2.top();
            }

            st2.push(i);
        }

        for(int i = n-1; i>=0; i--){
            while(!st3.empty() && nums[st3.top()] <= nums[i]){
                st3.pop();
            }
            if(st3.empty()){
                nge[i] = n;
            }else{
                nge[i] = st3.top();
            }

            st3.push(i);
        }

        for(int i = 0; i < n; i++){
            while(!st4.empty() && nums[st4.top()] < nums[i]){
                st4.pop();
            }
            if(st4.empty()){
                pgee[i] = -1;
            }else{
                pgee[i] = st4.top();
            }

            st4.push(i);
        }
        const long long mod = 1000000007LL;
        long long smallest = 0;
        long long largest = 0;
        for(int i = 0; i < n; i++){
            long long leftS = (long long)(i - psee[i]);
            long long rightS = (long long)(nse[i] - i);
            smallest += leftS * rightS * nums[i];

            long long leftL = (long long)(i - pgee[i]);
            long long rightL = (long long)(nge[i] - i);
            long long val2 = (leftL * rightL)%mod;
            largest += leftL * rightL * nums[i];
        }

        return largest - smallest;
    }
};