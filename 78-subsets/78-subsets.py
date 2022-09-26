class Solution:
    def recursive(self, nums, res, s):
        if len(nums) <= 1:
            return
        
        for x in range(len(nums)):
            l = nums[:x] + nums[x+1:]
            t = tuple(l)

            if t not in s:
                res.append(l)
                s.add(t)
                self.recursive(l, res, s)
        
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[], nums]
        s = set(tuple(nums))
        self.recursive(nums, res, s)
        
        return res
        