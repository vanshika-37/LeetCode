class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, j = i + 1, d = 1;
        vector<string>ans;
        while(j < nums.size()){
            if (nums[j] == nums[i] + d){
                j++;
                d++;
            }
            else{
                if (nums[i] != nums[j - 1])
                    ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
                else{
                    ans.push_back(to_string(nums[i]));
                }
                i = j;
                j = i + 1;
                d = 1;
            }
        }
        if (i == nums.size() - 1){
            ans.push_back(to_string(nums[i]));
        }
        else if (i < nums.size()){
            ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
        }
        return ans;
    }
};