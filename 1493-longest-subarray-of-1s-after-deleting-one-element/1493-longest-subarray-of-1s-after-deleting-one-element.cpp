class Solution {
public:
    int lsa(vector<int>&nums, int n){
        vector<int>dp(n,0);
        int maxi = 0;
        dp[0] = nums[0] == 1 ? 1 : 0;
         maxi = max(maxi,dp[0]);
        for (int i = 1; i < n; i++){
            if (nums[i] == 1){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = 0;
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
    
    int longestSubarray(vector<int>& nums) {
        vector<int>z;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){ 
                z.push_back(i); 
            }
        }
        int m = z.size();
        if (m == 0) return n-1;
        if (m == n) return 0;
        int mx = 0;
        for (int i = 0; i < m; i++){
            nums.erase(nums.begin() + z[i]);
            mx = max(mx, lsa(nums,n-1));
            nums.insert(nums.begin()+z[i],0);
        }
        return mx;
    }
};