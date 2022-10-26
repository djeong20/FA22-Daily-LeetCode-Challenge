# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        
        q = collections.deque([])
        q.append(root)
        
        res = 1
        level = 1
        maxVal = root.val
        
        while q:
            val = 0
            n = len(q)
            for _ in range(n):
                node = q.popleft()
                val += node.val
                
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            
            if val > maxVal:
                maxVal = val
                res = level
            level += 1
        
        return res
        