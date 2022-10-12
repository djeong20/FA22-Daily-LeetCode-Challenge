
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        
        if s & 1 == 1:
            return False

        target = s // 2

        dp = [False] * (target+1)
        dp[0] = True
        
        for num in nums:
            for i in range(target, 0, -1):
                if i >= num:
                    dp[i] = dp[i] or dp[i-num]

        return dp[target]