class Solution {
public:
    bool isValid(string s) {
        stack<char>c;
        for (auto &x : s){
            if (x == '(' || x == '{' || x == '['){
                c.push(x);
            }
            else{
                if (c.empty()){
                    return false;
                }
                else if (x == ')'  and c.top() == '('){
                    c.pop();
                }
                else if (x == '}'  and c.top() == '{'){
                    c.pop();
                }
                else if (x == ']'  and c.top() == '['){
                    c.pop();
                }
                else{
                    return false;
                }
            }
        }
        return c.empty();
    }
};