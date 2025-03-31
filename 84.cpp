class Solution {
    public:
    
        vector<int> nextSElement(vector<int>& h){
            int n = h.size();
            stack<int> st;
            vector<int> ans(n);
            st.push(-1);
    
            for(int i = n-1; i >= 0; i--){
                while(st.top()!=-1 && h[st.top()] >= h[i]){
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int> prevSElement(vector<int>& h){
            int n = h.size();
            stack<int> st;
            vector<int> ans(n);
            st.push(-1);
    
            for(int i = 0; i < n; i++){
                while(st.top()!=-1 && h[st.top()] >= h[i]){
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> next(n);
            vector<int> prev(n);
            next = nextSElement(heights);
            prev = prevSElement(heights);
            
            int area = INT_MIN;
    
            for(int i = 0; i < n; i++){
                int l = heights[i];
                if(next[i]==-1){
                    next[i] = n;
                }
                int b = next[i]-prev[i]-1;
                int new_arr = l*b;
                area = max(area,new_arr);
            }
            return area;
        }
    };