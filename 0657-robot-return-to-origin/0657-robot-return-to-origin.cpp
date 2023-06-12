class Solution {
public:
    bool judgeCircle(string moves) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < moves.size(); i++){
            if (moves[i] == 'L'){
                s1 -= 1;
            }
            else if (moves[i] == 'R'){
                s1 += 1;
            }
            else if (moves[i] == 'U'){
                s2 -= 1;
            }
            else if (moves[i] == 'D'){
                s2 += 1;
            }
        }
        return ((s1 == 0) and (s2 == 0));
    }
};