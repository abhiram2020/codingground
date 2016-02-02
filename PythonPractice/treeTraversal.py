import sys

class node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

def inOrderTrav(node):
    if node is not None:
        inOrderTrav(node.left)
        print node.data
        inOrderTrav(node.right)
        
def preOrderTrav(node):
    if node is not None:
        print node.data
        preOrderTrav(node.left)
        preOrderTrav(node.right)

def postOrderTrav(node):
    if node is not None:
        postOrderTrav(node.left)
        postOrderTrav(node.right)
        print node.data

root = node(1)
root.left = node(2)
root.right = node(3)
root.left.left = node(4)
root.left.right = node(5)

print "INORDER TRAVERSAL"
inOrderTrav(root)

print "PREORDER TRAVERSAL"
preOrderTrav(root)

print "POSTORDER TRAVERSAL"
postOrderTrav(root)


        
