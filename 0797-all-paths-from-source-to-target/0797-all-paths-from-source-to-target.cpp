class Solution {
public:
    void dfs(int& node, vector<bool>&visited, vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>&curr, int& end){
        if (visited[node] == true) return;
        if (node == end){
            res.push_back(curr);
            return;
        }
        visited[node] = true;
        for (int i = 0; i < graph[node].size();i++){
                curr.push_back(graph[node][i]);
                dfs(graph[node][i],visited,graph,res,curr,end);
                curr.pop_back();
            
        }
        visited[node] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>curr;
        int start = 0, end = graph.size() - 1;
        vector<bool>visited(end+1,false);
        curr.push_back(start);
        dfs(start, visited, graph, res, curr,end);
        return res;
    }
};