# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if root == None: 
            return res
        
        dq = collections.deque([])
        dq.append(root)
        n = 1
        
        while n > 0:
            for i in range(n):
                node = dq.popleft()
                if i == 0: res.append(node.val)
                if node.right != None: dq.append(node.right)
                if node.left != None: dq.append(node.left)
                
            n = len(dq)
            
        return res
        