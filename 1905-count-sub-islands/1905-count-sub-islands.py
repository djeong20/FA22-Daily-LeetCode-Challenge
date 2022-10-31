class Solution:
    def valid(self, grid, r, c, m, n):
        if 0 <= r < m and 0 <= c < n and grid[r][c] == 1:
            return True
        return False
    
    def traverseIsland(self, grid1, grid2, q, m, n):
        isSub = True
        
        while q:
            r, c = q.popleft()
            
            if grid1[r][c] == 0:
                isSub = False
            
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r+dr, c+dc
                
                if self.valid(grid2, nr, nc, m, n):
                    q.append((nr,nc))
                    grid2[nr][nc] = 0
                
        return isSub
        
    
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        # traverse islands in grid2
        # while traversing, check is corresponding cell is also an island in grid 1
        # if not, we don't consider it as subisland
        
        m, n = len(grid2), len(grid2[0])
        q = collections.deque([])
        count = 0
        
        for r in range(m):
            for c in range(n):
                if grid2[r][c] == 1:
                    grid2[r][c] = 0
                    q.append((r,c))
                    
                    if self.traverseIsland(grid1, grid2, q, m, n):
                        count += 1
        
        return count