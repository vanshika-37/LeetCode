class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>t;
        t.push_back({1});
        for (int i = 1; i <= rowIndex;i++){
            vector<int>temp;
            for (int j = 0; j < i+1; j++){
                if (j == 0 || j == i){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(t[i-1][j-1] + t[i-1][j]);
                }
            }
            t.push_back(temp);
        } 
        return t[t.size()-1];
    }
};