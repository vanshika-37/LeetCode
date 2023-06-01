class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(nums.size() == 1){
            return;
        }
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        
        reverse(nums.begin()+n - k, nums.end());
        
        reverse(nums.begin(), nums.end());
    }
};