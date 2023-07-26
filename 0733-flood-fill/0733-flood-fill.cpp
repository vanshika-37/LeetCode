class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //nsew
        // if (image[sr][sc] == 0){
        //     return image;
        // }
        int ori = image[sr][sc];
        int R = image.size(), C = image[0].size();
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,1,-1};
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(R, vector<bool>(C,false));
        q.push({sr,sc});
        image[sr][sc] = color;
        visited[sr][sc] = true;
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            int r = p.first, c = p.second;
            for (int i = 0; i < 4; i++){
                int rr = r + dr[i];
                int cc = c + dc[i];
               // cout << "rr: " << rr << " " << "cc " << cc << endl;
                if (rr < 0 || rr >= R) continue;
                if (cc < 0 || cc >= C) continue;
                if (visited[rr][cc]) continue;
                if (image[rr][cc] != ori) continue;
                visited[rr][cc] = true;
                image[rr][cc] = color;
                q.push({rr,cc});
            }
        }
        return image;
    }
};