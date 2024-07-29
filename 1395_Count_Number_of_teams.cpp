// Not Ideal way to do this question
// Need optimised version :(

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        int r = rating.size();
        // sort(rating.begin(),rating.end());
        for(int i = 0; i < rating.size(); i++){
            for(int j = i+1; j < rating.size(); j++){
                for(int k = j+1; k < rating.size(); k++){
                if((rating[i]<rating[j] && rating[j]<rating[k]) || (rating[i]>rating[j] && rating[j] > rating[k])){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};