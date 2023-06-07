class Solution {
public:
    int minFlips(int a, int b, int c) {
        int r = a | b;
        unsigned long num = 1;
        int count = 0;
        for (int i = 0; i < 31; i++){
            num = 1 << i;
            if (c & num){
                if (!(r & num)){
                    count += 1;
                }
            }
            else {
                if (a & num && b & num){
                    count += 2;
                }
                else if (a & num || b & num){
                    count += 1;
                }
            }
        }
        return count;
    }
};