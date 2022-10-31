class Solution:
    def isValid(self, s_map, t_map):
        for k in t_map:
            if k in s_map and s_map[k] >= t_map[k]:
                continue
            return False
        
        return True
    
    def insertChar(self, s_map, ch):
        if ch in s_map:
            s_map[ch] += 1
        else:
            s_map[ch] = 1
    
    def removeChar(self, s_map, ch):
        s_map[ch] -= 1
    
    def minWindow(self, s: str, t: str) -> str:
        # create hash table of answers
        t_map, s_map = dict(), dict()
        
        for ch in t:
            self.insertChar(t_map, ch)
        
        q, res = "", ""
        
        for ch in s:
            q += ch
            self.insertChar(s_map, ch)
            
            while self.isValid(s_map, t_map):
                if res == "":
                    res = q
                else:
                    if len(q) < len(res):
                        res = q
                        
                self.removeChar(s_map, q[0])
                q = q[1:]
            
        return res
        
        
        
        