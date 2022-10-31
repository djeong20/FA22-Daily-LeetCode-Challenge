class Solution:
    
    # 1 1 2
    # 2 2 1
    # 3 4 1
    
    # 4 3 2
    # 1 4 1
    
    
    # [7,6,1,1]
    # [2,7,6,0]
    # [1,3,5,1]
    # [6,6,3,2]
    
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        
        dp = [[0] * n for _ in range(m)]        
        
        def dfs(r, c):
            if not dp[r][c]:
                dp[r][c] = 1
                for dr, dc in directions:
                    nr, nc = r+dr, c+dc

                    if 0 <= nr < m and 0 <= nc < n and (nr, nc) and matrix[r][c] < matrix[nr][nc]:
                        
                        dp[r][c] = max(dp[r][c], dfs(nr, nc)+1)
            
            return dp[r][c]
        
        maxVal = 0
        for r in range(m):
            for c in range(n):
                v = dfs(r, c)
                maxVal = max(v, maxVal)
        
        return maxVal