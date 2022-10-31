class Solution:
    def bfs(self, grid, x, y, m, n):
        closed = True
        q = collections.deque([])
        q.append((x,y))
        
        while q:
            r, c = q.popleft()
            
            # island in edge (not closed)
            if r == 0 or r == m-1 or c == 0 or c == n-1:
                closed = False
            
            for dr, dc in [(-1,0), (1,0), (0, -1), (0, 1)]:
                nr, nc = r+dr, c+dc
                
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 0:
                    grid[nr][nc] = 1
                    q.append((nr, nc))
                    
        return closed
    
    def closedIsland(self, grid: List[List[int]]) -> int:
        # This is same as number of island that is not in edge
        
        # Strategy 1: iterate edge and flip islands in edge to 1. Then traverse grid and count nums 
        
        # Strategy 2: iterate grid and traverse island. If it's at the edge, do not increase num
        res = 0
        m, n = len(grid), len(grid[0])
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 0:
                    grid[r][c] = 1
                    
                    if self.bfs(grid, r, c, m, n):
                        res += 1
                    
        return res