class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int my = (c[1][1] - c[0][1]);
        int mx = (c[1][0] - c[0][0]);
        for (int i = 2; i < c.size(); i++){
            if ((mx * (c[i][1] - c[i-1][1])) != (my * (c[i][0] - c[i-1][0]))){
                return false;
            }
        }
        return true;
    }
};