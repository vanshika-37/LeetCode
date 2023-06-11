class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = size(nums);
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = temp.size() - 1;
        for (int i = 1; i < n; i++){
            if (nums[i] > temp[len]){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len + 1;
            
    }
};
