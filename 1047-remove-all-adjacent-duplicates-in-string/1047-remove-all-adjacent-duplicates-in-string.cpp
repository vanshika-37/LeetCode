class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>c;
        c.push(s[0]);
        string ans = "";
        for (int i = 1; i < s.length();i++){
            if (c.empty()){
                c.push(s[i]);
            }
            else if (s[i] == c.top()){
                c.pop();
            }
            else{
                c.push(s[i]);
            }
        }
        while(!c.empty()){
            ans.push_back(c.top());
            c.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};