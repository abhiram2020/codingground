import sys

class node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

#Function to Determine the Size of the Tree
def treeSize(node):
    if node is None:
        return 0
    return treeSize(node.left) + 1 + treeSize(node.right)

#Form the Tree
root = node(1)
root.left = node(2)
root.right = node(3)
root.left.left = node(4)
root.left.right = node(5)

print "Tree Size: ",treeSize(root)
