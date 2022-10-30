class Solution:
    # 0 0 0 : None
    # 0 0 1 : Pacific
    # 0 1 0 : Atlantic
    # 0 1 1 : Both
    
    
    def dfs(self, heights, r, c,  visited, d):
        if (r,c) in d:
            return d[(r,c)]
        
        direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        m, n = len(heights), len(heights[0])
        res = 0
        
        if r == 0: res = res | 1
        if r == m-1: res = res | 2
        if c == 0: res = res | 1
        if c == n-1: res = res | 2
            
        if res == 3: return res
        
        visited.add((r,c))
        h = heights[r][c]
        
        for dr, dc in direction:
            x, y = r+dr, c+dc
            
            if x < 0 or x >= m or y < 0 or y >= n or h < heights[x][y] or (x,y) in visited:
                continue
            
            res = res | self.dfs(heights, x, y, visited, d)
        
        return res
    
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        res = []
        
        d = dict()
        
        for r in range(m):
            for c in range(n):
                
                d[(r,c)] = self.dfs(heights, r, c, set(), d)
                
                if d[(r,c)] == 3:
                    res.append([r,c])
                    
        return res