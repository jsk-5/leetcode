#https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        result = []
        stack = [root]
        while stack:
            layer = []
            for i in range(len(stack)):
                node = stack.pop(0)
                # print(node)
                
                if(node):
                    layer.append(str(node.val))
                    stack.append(node.left)
                    stack.append(node.right)
                if(not node):
                    layer.append('N')

            result.append(",".join(layer))

        # print(",".join(result))

        return ",".join(result)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        
        layers = data.split(",")
        
        # print(layers)
        if(layers[0] == "N"):

            return None
        root = TreeNode(int(layers[0]))
        stack = [root]
        layers.pop(0)
        while stack:
            node = stack.pop(0)
            next_char = layers.pop(0)
            # print(next_char)

            if(next_char == 'N'):
                node.left = None
            else:
                node.left = TreeNode(int(next_char))
                stack.append(node.left)

            next_char = layers.pop(0) 
            # print(next_char)
            if(next_char == 'N'):
                node.right = None
            else:
                node.right = TreeNode(int(next_char))
                stack.append(node.right)
            # print(stack)
        return root




# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))