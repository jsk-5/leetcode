# Definition for a binary tree node.

#My Solution
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# class Solution:
#     def maxDepth(self, root: Optional[TreeNode]) -> int:
#         if not root:
#             return 0
#         depth = 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
#         root.val = depth
#         return depth
    

#     def isBalanced(self, root: Optional[TreeNode]) -> bool:
#         depthTree = root
#         self.maxDepth(depthTree)

#         queue = [root]

#         while queue:
#             node = queue.pop()
#             print(node)
#             left_depth = None
#             right_depth = None
#             if(node):
#                 if(node.left):
#                     left_depth = node.left.val
#                 else:
#                     left_depth = 0
#                 if(node.right):
#                     right_depth = node.right.val
#                 else:
#                     right_depth = 0
#                 if(abs(left_depth - right_depth) > 1):
#                     return False
#                 queue.append(node.left)
#                 queue.append(node.right)
#         return True
#         # print(depthTree)

#Optimal solution
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return (self.Height(root) >= 0)
    def Height(self, root: Optional[TreeNode]) -> bool:
        if root is None:  return 0
        leftheight, rightheight = self.Height(root.left), self.Height(root.right)
        if leftheight < 0 or rightheight < 0 or abs(leftheight - rightheight) > 1:  return -1
        return max(leftheight, rightheight) + 1