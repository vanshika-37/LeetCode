class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if ((mat.size()*mat[0].size()) > (r*c)){
            return mat;
        }
        vector<vector<int>>v(r,vector<int>(c,INT_MAX));
        vector<int>temp;
        for (auto x : mat){
            for (auto y : x){
                temp.push_back(y);
            }
        }
        int k = 0;
        for (int i = 0; i < r;i++){
            for (int j = 0; j < c and k < temp.size(); j++){
                v[i][j] = temp[k++];
            }
        }
        
        for (auto x : v){
            for (auto y : x){
                if (y == INT_MAX){
                    return mat;
                }
            }
        }
        return v;
    }
};