class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0;
        int n = players.size(); 
        int j = 0;
        int m = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        // players --> 4 7 9
        // trianers--> 2 5 8 8
        int count = 0;

        while(i < n && j < m){
            if(players[i] <= trainers[j]){
                i++;
                j++;
                count++;
            }else if(players[i] > trainers[j]){
                j++;
            }
        }
        return count;
    }
};