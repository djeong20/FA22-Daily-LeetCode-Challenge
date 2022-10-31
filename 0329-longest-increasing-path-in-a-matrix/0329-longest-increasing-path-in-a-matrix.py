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
        
        p_matrix = [[0]*n for _ in range(m)]        
        
        def dfs(r, c, matrix, p_matrix, visited):
            res = 1
            
            visited.add((r, c))
            
            for dr, dc in directions:
                nr, nc = r+dr, c+dc
                
                if 0 <= nr < m and 0 <= nc < n and (nr, nc) not in visited and matrix[r][c] < matrix[nr][nc]:
                    if p_matrix[nr][nc] != 0:
                        res = max(res, p_matrix[nr][nc]+1)
                    else:
                        res = max(res, dfs(nr, nc, matrix, p_matrix, visited.copy())+1)
                
            p_matrix[r][c] = res
            
            return p_matrix[r][c]
        
        maxVal = 0
        for r in range(m):
            for c in range(n):
                v = dfs(r, c, matrix, p_matrix, set())
                maxVal = max(v, maxVal)
        
        print(p_matrix)
        
        return maxVal