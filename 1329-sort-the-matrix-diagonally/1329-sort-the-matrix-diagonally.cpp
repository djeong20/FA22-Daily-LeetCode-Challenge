class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        
        
        unordered_map<int, priority_queue<int, std::vector<int>, std::greater<int>>> mp;
        
        vector<vector<int>> m;
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mp[i-j].push(mat[i][j]);
            }
        }
        
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mat[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }
        
        return mat;
    }
};