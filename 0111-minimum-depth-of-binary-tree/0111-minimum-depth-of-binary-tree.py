# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        
        if root == None:
            return 0
        
        depth = 1
        dq = collections.deque([])
        dq.append(root)
        
        while dq:
            n = len(dq)
            
            for _ in range(n):
                node = dq.popleft()

                if node.left == None and node.right == None:
                    return depth
                if node.left != None:
                    dq.append(node.left)
                if node.right != None:
                    dq.append(node.right)
            
            depth += 1
        
        
        
        