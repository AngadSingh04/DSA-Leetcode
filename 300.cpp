class Solution {
public:
    int getMax(int ind, int prev, int n, vector<int>& arr, 
    vector<int>& front, vector<int>& curr){

        for(int i = n-1; i >= 0; i--){
            for(int j = i-1; j >= -1; j--){
                int take = 0;
                if(j == -1 || arr[i] > arr[j]){
                    take = 1 + front[i+1];
                }
                int ntake = front[j+1];
                curr[j+1] = max(take,ntake);
            }
            front = curr;
        }
        
        return front[0];
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int prev = -1;
        vector<int> front(n+1, 0);
        vector<int> curr(n+1, 0);
        
        return getMax(0, prev, n, arr, front, curr);
    }
};

//optimal

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n , 1);

        // 5 4 11 1 16 8
        // 5 4

        for(int i = 0; i < n; i++){
            int tmp = 1;
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    tmp = max(tmp, dp[i] + dp[j]);
                }
            }
            dp[i] = tmp;
        }

        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

// more optimal version for getting count

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n =arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);

        for(int i = 0; i < n; i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
            }else{
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }

        return temp.size();
    }
};