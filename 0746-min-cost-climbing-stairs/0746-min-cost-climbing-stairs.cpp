class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>v(n,0);
        v[0] = cost[0];
        v[1] = cost[1]; 
        for (int i = 2; i < n; i++){
            v[i] = min(v[i-1],v[i-2]) + cost[i];
        }
        return min(v[n-1], v[n-2]);
    }
};