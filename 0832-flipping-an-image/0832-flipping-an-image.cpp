class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size();i++){
            int low = 0, high = image.size()-1;
            while(low < high){
                swap(image[i][low], image[i][high]);
                image[i][low] = !image[i][low];
                image[i][high] = !image[i][high];
                low++;
                high--;
            }
            if (image.size() & 1)
                image[i][low] = !image[i][low];
        }
        return image;
    }
};