class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        count = 0
        
        q = collections.deque([])
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] == '1':
                    grid[r][c] = '0'
                    q.append((r,c))
                    
                    while q:
                        sr, sc = q.popleft()
                        
                        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            nr, nc = sr+dr, sc+dc
                            
                            if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == '1':
                                grid[nr][nc] = '0'
                                q.append((nr,nc)) 

                    count += 1
                    
                    q.clear()
        
        return count