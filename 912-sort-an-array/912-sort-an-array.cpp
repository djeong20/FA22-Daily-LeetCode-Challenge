class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        
        for (auto n : nums) {
            pq.push(n);
        }
        
        std::vector<int> res;
        
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};