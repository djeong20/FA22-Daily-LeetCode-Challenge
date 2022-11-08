class Solution {
public:
    vector<vector<int>> result;
    
    void solve(vector<int>& candidates, vector<int> items, int idx, int target) {
        if (target == 0) {
            result.push_back(items);
            return;
        }
        
        if (idx == candidates.size()) return;
        
        if (target > 0) {
            // choose curr or move to next
            int val = candidates[idx];
            
            // 1. move next
            solve(candidates, items, idx+1, target);
            
            // 2. choose curr
            items.push_back(val);
            solve(candidates, items, idx, target-val);
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> item;
        
        solve(candidates, item, 0, target);
        
        return result;
    }
};