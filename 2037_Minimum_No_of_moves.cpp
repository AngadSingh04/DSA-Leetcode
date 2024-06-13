class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(),students.end());
        vector<int> absolute_d(seats.size());
        for(int i = 0; i < seats.size(); i++){
            absolute_d[i] = abs(seats[i]-students[i]);
        }
        int moves = 0;
        for(int i = 0; i < absolute_d.size(); i++){
            moves += absolute_d[i];
        }
        return moves;
    }
};