# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        
        q = collections.deque([])
        
        q.append(original)
        q.append(cloned)
        
        while q:
            og = q.popleft()
            cl = q.popleft()
            
            if og == target:
                return cl
            
            if og.left:
                q.append(og.left)
                q.append(cl.left)
            if og.right:
                q.append(og.right)
                q.append(cl.right)
        