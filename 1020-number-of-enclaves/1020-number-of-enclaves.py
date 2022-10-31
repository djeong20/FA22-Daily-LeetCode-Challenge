class Solution:
    def bfs(self, grid, q, m, n):
        count = 1
        boundary = False
        
        while q:
            r, c = q.popleft()
            
            # boundary
            if r == 0 or r == m-1 or c == 0 or c == n-1:
                boundary = True
            
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r+dr, c+dc
                
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                    grid[nr][nc] = 0
                    q.append((nr,nc))
                    count += 1
        
        if boundary:
            return 0
        
        return count
            
            
    def numEnclaves(self, grid: List[List[int]]) -> int:
        res = 0
        m, n = len(grid), len(grid[0])
        q = collections.deque([])
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    grid[r][c] = 0
                    q.append((r,c))
                    res += self.bfs(grid, q, m, n)
                    
        return res
        