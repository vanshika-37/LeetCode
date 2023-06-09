class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size()-1;
        int ind = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if (letters[mid] <= target){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return low == letters.size() ? letters[0] : letters[low];
    }
};