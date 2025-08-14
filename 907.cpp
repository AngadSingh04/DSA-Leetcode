class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1000000007;
        vector<int> psee(n);
        vector<int> nse(n);
        stack<int> st1;
        stack<int> st2;

        for(int i = n-1; i>=0; i--){
            while(!st1.empty() && arr[st1.top()] >= arr[i]){
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
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                st2.pop();
            }
            if(st2.empty()){
                psee[i] = -1;
            }else{
                psee[i] = st2.top();
            }

            st2.push(i);
        }

        int total = 0;
        for(int i = 0; i < n; i++){
            long left = i - psee[i];
            long right = nse[i] - i;

            total = (total + (((left*right)%mod) * arr[i])%mod)%mod;
        }

        return total;
    }
};