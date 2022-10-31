class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        s_count, t_count = [0] * 26, [0] * 26
        base = ord('a')
        
        for i in range(len(s)):
            si = ord(s[i]) - base
            ti = ord(t[i]) - base
            
            s_count[si] += 1
            t_count[ti] += 1
            
        return s_count == t_count
         