class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] += nums[i];
        }
        set<int> v;
        for (auto& x : nums) {
            v.insert(x);
        }
        vector<int> s;
        for (auto& x : v) {
            s.push_back(x);
        }
        sort(s.begin(), s.end());
        vector<int> dp(s.size());
        if (s.size() == 1) {
            return mp.begin()->second;
        }
        map<int, int>::iterator it = mp.begin();
        dp[0] = mp.begin()->second;

        it = next(it, 1);
        if (s[1] == s[0] + 1) {
            dp[1] = max(dp[0], it->second);
        } else {
            dp[1] = dp[0] + it->second;
        }
        int i = 2;
        for (it = next(it, 1); it != mp.end(); it++) {
            if (s[i] - 1 == s[i - 1]) {
                dp[i] = max(dp[i - 2] + it->second, dp[i - 1]);
            } else {
                dp[i] = dp[i - 1] + it->second;
            }
            i++;
        }
        return dp[s.size() - 1]; 
    }
};
