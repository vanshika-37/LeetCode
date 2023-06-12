class Solution {
public:
    bool canConstruct(string r, string m) {
        int i = 0; 
        int j = 0;
        sort(r.begin(), r.end());
        sort(m.begin(), m.end());
        while(i < r.length() and j < m.length()){
            if (r[i] == m[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if (i == r.length()){
            return true;
        }
        return false;
    }
};