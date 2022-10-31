# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        
        q = collections.deque([])
        q.append((root, None))
        v = root.val
        
        xx, yy = None, None
        
        while q:
            n = len(q)
            
            for _ in range(n):
                node, parent = q.popleft()
                
                if node.val == x:
                    xx = parent
                if node.val == y:
                    yy = parent

                if node.left:
                    q.append((node.left, node))
                if node.right:
                    q.append((node.right, node))
            
            if xx != None and yy != None and xx != yy:
                return True
            if xx != None or yy != None:
                return False
            
        return False