class Solution {
public:

    bool isCycle(int node, vector<int>adj[2000], vector<bool> &marked, vector<bool> &dmarked){
        marked[node] = true;
        dmarked[node] = true;
        for (int i = 0; i < adj[node].size(); i++){
            if (marked[adj[node][i]] == false){
                if (isCycle(adj[node][i], adj, marked, dmarked)){
                    return true;
                }
            }
            else if (dmarked[adj[node][i]] == true){
                return true;
            }
        }
        dmarked[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0)
            return true;   
        vector<int>adj[2000];
        for (int i = 0; i < prerequisites.size(); i++){
            if (prerequisites[i][0] == prerequisites[i][1]){
                return false;
            }
           adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int h = 0;
        for (auto x : adj){
            cout << h << " ";
            for (auto y : x){
                cout << y << " ";
            }
            h++;
            cout << endl;
        }
        vector<bool>marked(numCourses,0);
        vector<bool>dmarked(numCourses,0); 
        for (int i = 0; i < numCourses; i++){
            if (marked[i] == false and adj[i].size() != 0){
                if (isCycle(i,adj,marked,dmarked))
                    return false;
            }
        }
        return true;
    }
};