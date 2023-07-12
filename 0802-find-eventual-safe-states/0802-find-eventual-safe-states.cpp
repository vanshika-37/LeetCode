class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& ans, vector<int>& visited, int num) {
        if (visited[num] == 1) return false;
        if (visited[num] == 2) return true;

        visited[num] = 1;

        for (int i = 0; i < graph[num].size(); i++) {
            if (!dfs(graph, ans, visited, graph[num][i]))
                return false;
        }

        visited[num] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dfs(graph, ans, visited, i))
                ans.push_back(i);
        }

        return ans;
    }
};
