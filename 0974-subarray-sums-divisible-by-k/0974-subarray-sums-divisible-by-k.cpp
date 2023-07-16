class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int prefix_sum = 0, count = 0;;
        for (int i = 0; i < nums.size(); i++){
            prefix_sum = (prefix_sum + nums[i]) % k;
            if (prefix_sum < 0) prefix_sum += k;
            count += mp[prefix_sum];
            mp[prefix_sum]++;
        }
        return count;
    }
};