# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def findTwoSum(node, k, visited):
    if node == None:
        return False

    target = k - node.val

    if target in visited:
        return True

    visited.add(node.val)

    return findTwoSum(node.left, k, visited) or findTwoSum(node.right, k, visited)

class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:    
        return findTwoSum(root, k, set())
            
        
        
        
        