class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (currSum + nums[i] < 0){
                currSum = 0;
            }
            else{
                currSum += nums[i];
            }
            maxSum = max(maxSum, currSum);
        }
        if (maxSum == 0){
            return *max_element(nums.begin(), nums.end());
        }
        return maxSum;
    }
};