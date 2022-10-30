class Solution:
    def visit(self, grid, r, c, visited):
        m, n = len(grid), len(grid[0])
        
        visited.add((r,c))
        
        if r > 0 and grid[r-1][c] == 1:
            grid[r-1][c] = 0
            self.visit(grid, r-1, c, visited)
        if r < m-1 and grid[r+1][c] == 1:
            grid[r+1][c] = 0
            self.visit(grid, r+1, c, visited)
        if c > 0 and grid[r][c-1] == 1:
            grid[r][c-1] = 0
            self.visit(grid, r, c-1, visited)
        if c < n-1 and grid[r][c+1] == 1:
            grid[r][c+1] = 0
            self.visit(grid, r, c+1, visited)
        
        return len(visited)
        
        
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxArea = 0
        
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                
                if grid[r][c] == 1:
                    grid[r][c] = 0
                    area = self.visit(grid, r, c, set())
                    
                    maxArea = max(area, maxArea)
                    
        return maxArea
        