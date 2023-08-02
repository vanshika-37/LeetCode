class Solution {
public:
    void solve (vector<int>&nums, vector<int>op, vector<vector<int>>&ans, int& n, int start){
             if (op.size() == n){
                ans.push_back(op);
                  return;
            }
           
        for (int i = 0; i < n; i++){
            if (find(op.begin(), op.end(), nums[i]) == op.end()){
                op.push_back(nums[i]);
                solve(nums,op,ans,n,i+1);
                op.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        int n = nums.size();
        solve(nums,op,ans,n,0);
        return ans;
    }
};