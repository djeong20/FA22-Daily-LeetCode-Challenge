class Solution:
    def traverse(self, matrix, r, c, val, m, n):
        while r+1 < m and c+1 < n:
            r += 1
            c += 1
            if matrix[r][c] != val:
                return False
        return True
    
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        m, n = len(matrix), len(matrix[0])
        
        # 1. column traversal
        for col in range(n):
            if not self.traverse(matrix, 0, col, matrix[0][col], m, n):
                return False
                
        # 2. row traversal
        for row in range(1, m):
            if not self.traverse(matrix, row, 0, matrix[row][0], m, n):
                return False
        
        return True