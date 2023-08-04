class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&arr, int cnt, int sum, vector<int>op, int& target){
        if (cnt >= arr.size()){
            return;
        }
        if (arr[cnt] + sum == target){
            op.push_back(arr[cnt]);
            ans.push_back(op);
            return;
        }
        if (sum + arr[cnt] < target){
            vector<int>op1 = op;
            vector<int>op2 = op;
            op2.push_back(arr[cnt]);
            solve(arr,cnt,sum+arr[cnt],op2,target);
            solve(arr,cnt+1,sum,op1,target);
        }
        else{
            solve(arr,cnt+1,sum,op,target);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        ans.clear();
        sort(arr.begin(), arr.end());
        vector<int>op;
        solve(arr,0,0,op,target);
        return ans;
    }
};