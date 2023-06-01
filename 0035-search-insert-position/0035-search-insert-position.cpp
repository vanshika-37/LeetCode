class Solution {
public:
    //1 2 4 5
    // 3
    int search(vector<int>nums, int k, int s, int e){
        if (s <= e){
            int mid = s + (e-s)/2;
            if (nums[mid] == k){
                return mid;
            }
            else if (nums[mid] > k){
                return search(nums,k,s,mid-1);
            }
            else{
                return search(nums,k,mid+1,e);
            }
        }
        return s;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int ind = search(nums,target,s,e);
        return ind;
    }
};