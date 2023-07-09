class Solution {
public:
    void solve(vector<int>nums,vector<int>op,vector<vector<int>>&subs){
        if(nums.size() == 0){
            subs.push_back(op);
            return;
        }
        int temp = nums[0];
        nums.erase(nums.begin());
        solve(nums,op,subs);
        op.push_back(temp);
        solve(nums,op,subs);
    }
    
    int findXOR(vector<int>&v){
        if (!v.size()) return 0;
        int xoro = v[0];
        for (int i=1; i < v.size(); i++){
            xoro = xoro ^ v[i];
        }
        return xoro;
    }
    
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>subs;
        vector<int>op;
        solve(nums,op,subs);
        int xoro = 0;
        for (int i = 0; i < subs.size(); i++){
            xoro += findXOR(subs[i]);
        }
        return xoro;
    }
};