class Solution:
    def recursive(self, nums, res):
        if len(nums) <= 1:
            return
        
        for x in range(len(nums)):
            l = nums[:x] + nums[x+1:]
            if l not in res:
                res.append(l)
                self.recursive(l, res)
        
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        res = [[], nums]
        self.recursive(nums, res)
        
        return res
        