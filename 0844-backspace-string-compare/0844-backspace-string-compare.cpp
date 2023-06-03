class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>s1,s2;
        int i = 0, j = 0;
        while(i < s.length()){
            if (s[i] != '#'){
                s1.push(s[i]);
            }
            else if (!s1.empty()){
                s1.pop();
            }
            i++;
        }
        while(j < t.length()){
            if (t[j] != '#'){
                s2.push(t[j]);
            }
            else if (!s2.empty()){
                s2.pop();
            }
            j++;
        }
        while(!s1.empty() and !s2.empty()){
            if (s1.top() != s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        if (!s1.empty() || !s2.empty()){
            return false;
        }
        return true;
    }
};