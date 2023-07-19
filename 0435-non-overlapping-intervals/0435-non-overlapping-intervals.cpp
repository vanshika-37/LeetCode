class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 1, count = 0;
        int lastEnd = intervals[0][1];
        while (i < intervals.size()){
            if (lastEnd <= intervals[i][0]){
                lastEnd = intervals[i][1];
                
            }
            else {
                ++count;
                lastEnd = min(lastEnd,intervals[i][1]);
            }
            ++i;
        }
        return count;
    }
};