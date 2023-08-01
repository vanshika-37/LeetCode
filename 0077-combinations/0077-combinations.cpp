class Solution {
public:
    void solve(vector<int>&op, vector<vector<int>>&ans, int &k, int cnt, int &n){
        if (op.size() == k){
            ans.push_back(op);
            return;
        }
        
        for (int i = cnt; i <= n; i++){
            op.push_back(i);
            solve(op,ans,k,i+1,n);
            op.pop_back();
        }   
    }
    
    vector<vector<int>> combine(int n, int k) {
       
        vector<int>op;
        vector<vector<int>>ans;
        solve(op,ans,k,1,n);
        return ans;
    }
};