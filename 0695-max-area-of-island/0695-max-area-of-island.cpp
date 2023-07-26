class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,1,-1};
        int R = grid.size(), C = grid[0].size();
        int mx = 0,r = 0, c = 0;
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if (grid[i][j] == 1){
                    queue<pair<int,int>>q;
                    int size = 1;
                    q.push({i,j});
                    grid[i][j] = 2;
                    while(!q.empty()){
                        r = q.front().first;
                        c = q.front().second;
                        q.pop();
                       // cout << "r " << r << " " << "c " << c << endl;
                        for (int k = 0; k < 4; k++){
                            int rr = r + dr[k];
                            int cc = c + dc[k];
                           // cout << "rr " << rr << " " << "cc " << cc << endl;
                            if (rr < 0 || rr >= R || cc < 0 || cc >= C || grid[rr][cc] != 1) continue;
                            
                            grid[rr][cc] = 2;
                            q.push({rr,cc});
                            size++;
                          //  cout << "size: " << size << endl;
                            
                        }
                    }
                    mx = max(mx,size);
                }
            }
        }
        return mx;
    }
};