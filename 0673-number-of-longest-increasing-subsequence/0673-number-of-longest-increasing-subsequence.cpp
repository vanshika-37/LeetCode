class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
     // longest increasing binary wale mai jitni baar we call binary search 
        int n = nums.size();
        vector<int>len(n,1);
        vector<int>count(n,1);
        int mx = INT_MIN;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    if (len[i] < len[j] + 1){
                        len[i] = len[j] + 1;
                        count[i] = 0;
                    }
                    if (len[j] + 1 == len[i]){
                        count[i] += count[j];
                    }
                }
            }
        }
        mx = *max_element(len.begin(), len.end());
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (len[i] == mx){
                ans += count[i];
            }
        }           
        return ans;
    }
};