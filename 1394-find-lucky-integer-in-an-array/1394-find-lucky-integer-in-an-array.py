class Solution:
    def findLucky(self, arr: List[int]) -> int:
        count = dict()
        
        for i in arr:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        
        res = -1
        
        for key in count:
            if key == count[key]:
                res = max(res, count[key])
                
        return res
            