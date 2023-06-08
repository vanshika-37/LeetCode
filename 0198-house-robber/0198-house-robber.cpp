class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        if (n == 2){
            return max(nums[0], nums[1]);
        }
        for (int i = 2; i < n; i++){
            int maxi = INT_MIN;
            for (int j = 0; j < i - 1; j++){
                maxi = max(maxi, nums[j]);
            }
            nums[i] += maxi;
        }
        return max(nums[n-1], nums[n-2]);
    }
};