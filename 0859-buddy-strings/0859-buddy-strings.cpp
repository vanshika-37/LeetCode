class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int count = 0;
        int n = s.size(), m = goal.size();
        if (n != m || n == 1) return false;
        if (s == goal){
            sort(s.begin(),s.end());
            for (int i = 0; i < n-1; i++){
                if (s[i] == s[i+1]){
                    return true;
                }
            }
            return false;
        }
        int i = 0, j = 0;
        int ind1 = -1, ind2 = -1;
        while(i < n and j < m){
            if (s[i] != goal[j]){
                if (!count) ind1 = i;
                if (count == 1) ind2 = i;
                if (count > 1) return false;
                count++;
            }
            i++;
            j++;
        }
        if (ind1 == -1 || ind2 == -1) return false;
        swap(s[ind1],s[ind2]);
        return s == goal;
    }
};