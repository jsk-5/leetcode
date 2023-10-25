# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#Recursive
# class Solution:
#     def maxDepth(self, root: Optional[TreeNode]) -> int:
#         if not root:
#             return 0
        
#         return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

#DFS
# class Solution:
    # def maxDepth(self, root: Optional[TreeNode]) -> int:
    #     queue = [[root,0]]
    #     maxDepthResult = 0

    #     while queue:
    #         node, depth = queue.pop()
    #         maxDepthResult = max(maxDepthResult, depth)
    #         if node:
    #             queue.append([node.left, depth + 1])
    #             queue.append([node.right, depth +1])
                
    #     return maxDepthResult
        
#BFS
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        queue = [root]
        depth = -1

        while queue:
            

            for i in range(len(queue)):
                node = queue.pop(0)
                if node:
                    queue.append(node.left)
                    queue.append(node.right)
                    
            depth += 1

        return depth
