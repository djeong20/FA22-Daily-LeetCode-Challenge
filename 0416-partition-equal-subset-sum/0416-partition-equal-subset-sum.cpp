class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int n : nums) {
            total += n;
        }
        
        if (total % 2 == 1) return false;
        total /= 2;
        
        vector<bool> dp(total+1, false);
        dp[0] = true;
        
        for (int n : nums) {
            for (int i = total; i >= n; i--) {
                dp[i] = dp[i] || dp[i-n];
            }
            if (dp[total]) return true;
        }
        
        return dp[total];
    }
};