class Solution {
public:
    void solve(vector<int>nums, set<vector<int>>&ans, set<int>op){
        if (nums.size() == 0){
            vector<int>op1;
            for (auto x : op){
                op1.push_back(x);
            }
            ans.insert(op1);
            return;
        }
        int temp = nums[0];
        nums.erase(nums.begin());
        solve(nums,ans,op);
        op.insert(temp);
        solve(nums,ans,op);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>ans;
        set<int>op;
        solve(nums,ans,op);
        vector<vector<int>>anss;
        for (auto x : ans){
            anss.push_back(x);
        }
        return anss;
    }
};