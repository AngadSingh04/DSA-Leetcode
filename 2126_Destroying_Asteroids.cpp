class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());
        long long a = mass;
        for(int i = 0; i < asteroids.size(); i++){
            if(a >= asteroids[i]){
                a += asteroids[i];
            }else{
                return false;
            }
        }
        return true;
    }
};
