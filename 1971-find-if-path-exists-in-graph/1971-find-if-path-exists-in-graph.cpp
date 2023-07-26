class Solution {
public:
    bool dfs(int &node, int& destination, vector<int>adj[], vector<bool>&visited){
        if (visited[node]) return false;
        if (node == destination){
            return true;
        }
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++){
            if (dfs(adj[node][i], destination,adj,visited)){
                return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for (int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        return dfs(source, destination, adj, visited);
    }
};