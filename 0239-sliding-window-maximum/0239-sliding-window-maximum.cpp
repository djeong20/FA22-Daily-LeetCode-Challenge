class Solution {
public:
    deque<pair<int, int>> dq; // <val, index>
    
    void add(int val, int index, int k) {
        // Check if max is out of range
        if (!dq.empty() && dq.front().second <= index-k) {
            dq.pop_front();
        }
        
        // Add element
        while (!dq.empty() && dq.back().first < val) {
            dq.pop_back();
        }
        dq.push_back(make_pair(val, index));
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        
        for (int i = 0; i < k; i++) {
            add(nums.at(i), i, k);
        }
        res.push_back(dq.front().first);
        
        for (int i = k; i < nums.size(); i++) {
            add(nums.at(i), i, k);
            res.push_back(dq.front().first);
        }
        
        return res;
    }
};