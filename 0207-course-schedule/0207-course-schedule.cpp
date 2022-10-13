class Solution {
public:
    bool isCyclic(vector<int> adj[], vector<int> &vis, int id) {
        if (vis[id] == 1) return true;
        
        if (vis[id] == 0) {
            vis[id] = 1;
            
            for (auto edge : adj[id]) {
                if (isCyclic(adj, vis, edge)) {
                    return true;
                }
            }
        }
        
        vis[id] = 2;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for (auto v : prerequisites) {
            adj[v[1]].push_back(v[0]);
        }
        // check if cyclic
        std::vector<int> visited(numCourses,0);
        
        for (int i = 0; i < numCourses; i++) {
           if (isCyclic(adj, visited, i)) {
               return false;
           }
        }
        
        return true;
    }
};