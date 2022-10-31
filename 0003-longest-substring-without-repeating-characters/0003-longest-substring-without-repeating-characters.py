class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # sliding window
        
        q = collections.deque([])
        maxLen, n = 0, 0
        elements = set()
        
        for ch in s:
            
            # add new char
            q.append(ch)
            n += 1
            
            # check if new char exists in queue
            while ch in elements:
                elements.remove(q.popleft())
                n -= 1
            
            elements.add(ch)
            maxLen = max(n, maxLen)
            
        return maxLen
            
        
        