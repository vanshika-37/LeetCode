class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while(i + k < s.length()){
            reverse(s.begin() + i, s.begin() + i + k);
            i = i + 2 * k;
        }
        if (i < s.length()){
            reverse(s.begin() + i, s.end());
        }
        return s;
    }
};