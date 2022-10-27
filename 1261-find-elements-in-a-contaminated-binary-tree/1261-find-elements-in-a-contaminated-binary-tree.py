# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def recover(node, visited):
    if node == None:
        return
    
    visited.add(node.val)
    
    if node.left != None:
        node.left.val = node.val * 2 + 1
        recover(node.left, visited)
    
    if node.right != None:
        node.right.val = node.val * 2 + 2
        recover(node.right, visited)

class FindElements:
    def __init__(self, root: Optional[TreeNode]):
        root.val = 0
        self.visited = set()
        recover(root, self.visited)
        
    def find(self, target: int) -> bool:
        if target in self.visited:
            return True
        else:
            return False


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)