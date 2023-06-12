class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while(i < s.length()){
            while(i < s.length() and s[i] != ' '){
                i++;
            }
            reverse(s.begin() + j, s.begin() + i);
            j = i + 1;
            i++;
        }
        return s;
    }
};