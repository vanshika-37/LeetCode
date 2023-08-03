class Solution {
public:
    void solve(string& digits, unordered_map<int, string>& mp, string op, vector<string>& ans, int start) {
        if (op.length() == digits.length()) {
            ans.push_back(op);
            return;
        }
        
        for (int i = start; i < digits.length(); i++) {
            for (int j = 0; j < mp[digits[i] - '0'].length(); j++) {
                op.push_back(mp[digits[i] - '0'][j]);
                solve(digits, mp, op, ans, i + 1);
                op.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if (digits.length() == 0){
            return ans;
        }
        unordered_map<int, string> mp = {{2,"abc"}, {3,"def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"}};
        string op = "";
        solve(digits, mp, op, ans, 0);
        return ans;
    }
};
