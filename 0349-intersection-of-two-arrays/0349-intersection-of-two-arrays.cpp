class Solution {
public:
    void search(vector<int>n, int x,int s, int e, set<int>&ans){
        if (s <= e){
            int mid = s + (e-s)/2;
            if (n[mid] == x){
                ans.insert(x);
                return;
            }
            else if (n[mid] > x){
                search(n,x,s,mid-1,ans);
            }
            else{
                search(n,x,mid+1,e,ans);
            }
        }
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>ans;
        sort(nums1.begin(), nums1.end());
        for (auto x : nums2){
            search(nums1,x,0,nums1.size()-1,ans);
        }
        vector<int>c;
        for (auto x : ans){
            c.push_back(x);
        }
        return c;
    }
};