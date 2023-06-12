class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int cr = 0;
        string ans = "";
        while(i >=0 || j >=0){
            if(i >= 0){
                cr += a[i] - '0';
                i--;
            }
            if(j >= 0){
                cr += b[j] - '0';
                j--;
            }

            ans.push_back(cr%2 + '0');
            cr = cr / 2;
        }
        if(cr) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};