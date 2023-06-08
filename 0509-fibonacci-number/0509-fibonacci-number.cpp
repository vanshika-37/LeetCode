class Solution {
public:
    int fib(int n) {
        vector<int>v(3);
        v[0] = 0;
        v[1] = 1;
        if (n == 0 || n == 1){
            return v[n];
        }
        for (int i = 2; i <= n; i++){
            v[2] = v[0] + v[1];
            v[0] = v[1];
            v[1] = v[2];
        }
        return v[2];
    }
};