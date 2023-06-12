class Solution {
public:

    string countAndSay(int n) {
        if (n == 1){
            return "1";
        }
        string s = countAndSay(n-1);
        string res = "";
        int cnt = 1;
        for (int i = 0; i < s.length(); i++){
            if(s[i] == s[i+1])
            {
                cnt++;
            }
            else
            {
                res += to_string(cnt) + s[i];
                cnt = 1;
            }
        }
        
        return res;
    }
};