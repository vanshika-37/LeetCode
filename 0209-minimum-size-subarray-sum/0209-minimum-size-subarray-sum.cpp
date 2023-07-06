class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 1 and nums[0] >= target) return 1;
        else if (nums.size() == 1 and nums[0] < target) return 0;
        int s = 0, e = 0;
        int curr_size = 1, min_size = INT_MAX;
        int sum = nums[0];
        while(e < nums.size() and s < nums.size()){
            // cout << "sum: " << sum << " ";
            if (sum >= target){
                min_size = min(min_size, curr_size);
                sum -= nums[s];
                s++;
                curr_size--;
            }
            else{
                
                e++;
                if (e < nums.size()) {
                    sum += nums[e];
                    curr_size++;
               }                
            }
        }
        return min_size == INT_MAX ? 0 : min_size;
    }
};