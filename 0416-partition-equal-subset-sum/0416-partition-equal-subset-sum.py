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
    
#  0  1. 2. 3. 4. 5. 6. 7. 8. 9  10. 11     
# [T, F, F, F, F, F, F, F, F, F, F, F]

# num: 1
# [T, T, F, F, F, F, F, F, F, F, F, F]

# num: 5
# [T, T, F, F, F, T, T, F, F, F, F, F]

# num: 11
# [T, T, F, F, F, T, T, F, F, F, F, T]