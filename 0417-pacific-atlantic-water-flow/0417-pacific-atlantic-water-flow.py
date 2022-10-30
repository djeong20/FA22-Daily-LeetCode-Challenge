class Solution:
    # dfs from edges (pacific ocean, atlantic)
    
    def dfs(self, heights, r, c, visited):
        m, n = len(heights), len(heights[0])
        
        visited[r][c] = True
        h = heights[r][c]
        
        for dx, dy in self.dir:
            x, y = r + dx, c + dy
            
            # if visited, not in range, lower (cant move)
            if 0 <= x < m and 0 <= y < n and not visited[x][y] and heights[x][y] >= h:
                self.dfs(heights, x, y, visited)
            
    
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        res = []
        
        self.dir = [(-1,0), (1,0), (0,-1), (0,1)]
        pacific = [[False] * n for _ in range(m)]
        atlantic = [[False] * n for _ in range(m)]
        
        # traverse edges
        for i in range(n):
            self.dfs(heights, 0, i, pacific)
            
            self.dfs(heights, m-1, i, atlantic)
            
        for i in range(m):
            self.dfs(heights, i, 0, pacific)
            
            self.dfs(heights, i, n-1, atlantic)
        
        for r in range(m):
            for c in range(n):
                if pacific[r][c] and atlantic[r][c]:
                    res.append([r,c])
                    
        return res