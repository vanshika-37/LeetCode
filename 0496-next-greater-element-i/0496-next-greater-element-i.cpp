class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int,int> mp;
        s.push(INT_MAX);
        for( int i=nums2.size()-1; i >= 0 ; i-- ){
            int curr = nums2[i];
            if(curr)
            while(s.top() <= curr){
                s.pop();
            }
            mp[nums2[i]] = s.top()==INT_MAX?-1:s.top();
            s.push(curr);
        }
        vector<int> ans;
        for(auto i: nums1){
            ans.push_back(mp[i]); 
        }
        return ans;
    }
};