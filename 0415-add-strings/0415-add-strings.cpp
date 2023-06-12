class Solution {
public:
    string addStrings(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 and j >= 0){
            carry += ((a[i]) - 48);
            carry += ((b[j] - 48));
            res.push_back((carry%10)  + 48);
            carry = carry / 10;
            i--;
            j--;
        }
        while (i >= 0){
            carry += ((a[i]) - 48);
            res.push_back((carry%10) + 48);
            carry = carry / 10;
            i--;
        }
        while (j >= 0){
            carry += ((b[j]) - 48);
            res.push_back((carry%10) + 48);
            carry = carry / 10;
            j--;
        }
        if (carry){
            res.push_back((carry) + 48);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};