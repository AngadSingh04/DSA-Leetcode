class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int c = colors.size();
        int count = 0;
        vector<bool> alter(c,false);
        for(int i = 0; i < c; i++){
            if(colors[i] == 1){
                alter[i] = true;
            }
        }
        int a = alter.size();
        for(int i = 1; i < a-1; i++){
            if(alter[i] != alter[i-1] && alter[i] != alter[i+1]){
                count++;
            }
        }
        if(alter[0] != alter[a-1] && alter[0] != alter[1]){
                count++;
            }
            if(alter[0] != alter[a-1] && alter[a-1] != alter[a-2]){
                count++;
            }
        return count;
    }
};