class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color:
            return image
        
        m, n = len(image), len(image[0])
        
        q = collections.deque([])
        q.append((sr,sc))
        
        og = image[sr][sc]
        image[sr][sc] = color
        
        while q:
            r, c = q.popleft()
            
            for dr, dc in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
                nr, nc = r+dr, c+dc
                
                if 0 <= nr < m and 0 <= nc < n and image[nr][nc] == og:
                    image[nr][nc] = color
                    q.append((nr,nc))
        
        return image
        