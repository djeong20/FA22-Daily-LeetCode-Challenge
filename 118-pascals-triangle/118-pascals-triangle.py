class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1],[1,1]]
        if (numRows == 1):
            return [[1]]
        if (numRows == 2):
            return res
        
        curr = [1,1]
        
        for i in range(2, numRows):
            c = [1]
            for j in range(1, len(curr)):
                c.append(curr[j-1]+curr[j])
            
            c.append(1)
            res.append(c)
            curr = c
        return res
            
            