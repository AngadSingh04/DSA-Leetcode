class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        int x;
        t = t*2;
        x = num + t;
        return x;
    }
};