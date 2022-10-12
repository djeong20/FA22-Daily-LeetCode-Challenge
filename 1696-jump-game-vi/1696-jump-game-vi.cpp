class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        // decreasing queue (val, index). max index diff = k
        std::deque<std::pair<int, int>> monoQ;
        
        for (int i = 0; i < n; i++) {
            
            if (!monoQ.empty() && monoQ.front().second + k < i) {
                monoQ.pop_front();    
            }
            
            dp[i] = !monoQ.empty() ? nums[i] + monoQ.front().first : nums[i];
            // std::cout << "dp[" << i << "]: "<< dp[i] << std::endl;
            
            while (!monoQ.empty() && monoQ.back().first < dp[i]) {
                monoQ.pop_back();
            }
            
            monoQ.push_back({dp[i], i});
        }
        
        return dp[n-1];
    }
};