class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        N = len(nums)
        max_val = 0
        
        for i in range(N//2):
            
            val = nums[i] + nums[N-1-i]
            
            if val > max_val:
                max_val = val
                
        return max_val
            