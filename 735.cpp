class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> vc;

        // -2, -2, 1, 

        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }else{
                int a = abs(asteroids[i]);
                while(!st.empty() && st.top() > 0 && st.top() < a){
                    st.pop();
                }
                if(!st.empty() && st.top() == a){
                    st.pop();
                }else if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
            }
        }


        while(!st.empty()){
            vc.push_back(st.top());
            st.pop();
        }
        reverse(vc.begin(), vc.end());
        return vc;
    }
};