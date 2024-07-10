class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        int l = logs.size();
        for(int i = 0; i < l; i++){
            if(logs[i] == "../"){
                if(count > 0){
                    count--;
                }   
            }else if(logs[i] == "./"){
                count = count;
            }else{
                count++;
            }
        }
        return count;
    }
};