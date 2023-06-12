class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1, j = i;
        while(j >= 0 and s[j] == ' '){
            j--;
        }
        i = j;
        while(i >= 0 and s[i] != ' '){
            i--;
        }
        if (j == i){
            return j - i + 1;
        }
        return (j - i);
    }
};