class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() < 3){
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        int i = 1;
        if(nums[0] != nums[1]) return nums[0];
        while(i < nums.size() - 1){
            if (nums[i] != nums[i-1] and nums[i] != nums[i+1]){
                return nums[i];
            }
            i++;
        }
        return nums[nums.size()-1];
    }
};