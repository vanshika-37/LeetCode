class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,1,-1};
        int count = 0,r=0,c=0;
        vector<vector<bool>>visited(R,vector<bool>(C,false));
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if (!visited[i][j] and grid[i][j] == '1'){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        pair<int,int>p = q.front();
                        q.pop();
                        r = p.first, c = p.second;
                        for (int k = 0; k < 4; k++){
                            int rr = r + dr[k];
                            int cc = c + dc[k];
                            if (rr < 0 || rr >= R || cc < 0 || cc >= C || visited[rr][cc] || grid[rr][cc] == '0') continue;
                            visited[rr][cc] = true;
                            q.push({rr,cc});
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};