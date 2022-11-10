class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int, int> scores;
        
        for (auto p : matches) {
            if (scores.find(p[0]) == scores.end()) scores[p[0]] = 0;     
            if (scores.find(p[1]) == scores.end()) scores[p[1]] = 0;
            
            scores[p[1]] += 1;
        }
        
        vector<vector<int>> res(2, vector<int>());
        
        for (auto p : scores) {
            if (p.second == 0) res[0].push_back(p.first);
            if (p.second == 1) res[1].push_back(p.first);
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        
        return res;
    }
};