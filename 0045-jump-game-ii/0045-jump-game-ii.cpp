class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX-1);
        
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            // update jump index
            for (int j = 1; j <= nums[i] and (i+j) < n; j++) {
                dp[i+j] = min(dp[i+j], dp[i]+1);
            }
            if (dp[n-1] != INT_MAX-1) {
                return dp[n-1];
            }
        }
        return dp[n-1];
    }
    
    
    // [2, 3, 1, 1, 4]
    
    // i = 0
    // [0, m, m, m, m]
    // [0, 1, 1, m, m]
    
    // i = 1
    // [0, 1, 1, 2, 2]
    
};