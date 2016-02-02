import sys

class node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

def treeSize(node):
    if node is None:
        return 0
    return treeSize(node.left) + 1 + treeSize(node.right)

def identicalTrees(node_a,node_b):
    #if both the Nodes are NULL, Trees are Identical
    if node_a is None and node_b is None:
        return True
    #if both are not NULL, Compare the DATA and recurse over the
    #Child Trees
    if (node_a is not None and node_b is not None):
        return ((node_a.data == node_b.data) and
                identicalTrees(node_a.left,node_b.left) and
                identicalTrees(node_a.right,node_b.right))
    #if any one of them is NULL
    #return FALSE
    return False


def maxDepth(node):
    if node is None:
        return 0
    else:
        ldepth = maxDepth(node.left)
        rdepth = maxDepth(node.right)
        
        if ldepth > rdepth:
            return ldepth + 1
        else:
            return rdepth + 1

def minDepth(node):
    if node is None:
        return 0
    else:
        ldepth = minDepth(node.left)
        rdepth = minDepth(node.right)
        
        if ldepth < rdepth:
            return ldepth + 1
        else:
            return rdepth + 1

def deleteTree(node):
    if node is not None:
        deleteTree(node.left)
        deleteTree(node.right)
        del node

root1 = node(1)
root1.left = node(2)
root1.right = node(3)
root1.left.left = node(4)
root1.left.right = node(5)

root2 = node(1)
root2.left = node(2)
root2.right = node(3)
root2.left.left = node(4)
root2.left.right = node(5)

root3 = node(1)
root3.left = node(2)
root3.right = node(3)
root3.left.left = node(5)
root3.left.right = node(4)
root3.left.left.left = node(6)

print "Tree Size: ",treeSize(root1)

if(identicalTrees(root1,root2)):
    print "Identical TREES"
else:
    print "NON Identical TREES"

if(identicalTrees(root3,root2)):
    print "Identical TREES"
else:
    print "NON Identical TREES"
    
print "MinDepth: ",minDepth(root3),"\nMaxDepth: ",maxDepth(root3)

print "Deleting Tree"
deleteTree(root3)
