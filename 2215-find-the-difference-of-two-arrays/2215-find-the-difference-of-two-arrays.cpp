class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        for (int i = 0; i < nums1.size(); i++){
            s1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++){
            s2.insert(nums2[i]);
        }
        vector<vector<int>>ans;
        vector<int>v;
        set<int>t;
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(t, t.end()));
        for (auto& x: t){
            v.push_back(x);
        }
        ans.push_back(v);
        v.clear();
        t.clear();
        set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), inserter(t, t.end()));
        for (auto&x : t){
            v.push_back(x);
        }
        ans.push_back(v);
        return ans;
    }
};