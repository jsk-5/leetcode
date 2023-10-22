# https://leetcode.com/problems/diameter-of-binary-tree/solutions/1515564/python-easy-to-understand-solution-w-explanation/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        
        depthl = self.depthOfTree(root.left)
        depthr = self.depthOfTree(root.right)

        diameterl = self.diameterOfBinaryTree(root.left)
        diameterr = self.diameterOfBinaryTree(root.right)

        return max((depthl + depthr), diameterl, diameterr)

    def depthOfTree(self, root) -> int:
        if not root:
            return 0
        
        return 1 + max(self.depthOfTree(root.left), self.depthOfTree(root.right))
