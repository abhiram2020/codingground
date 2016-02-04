import sys
class node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

def findLCAUtil(root,n1,n2,v1,v2):
    if root is None:
        return None
    
    if root.data == n1:
        v1 = 1 #TRUE
        return root
    
    if root.data == n2:
        v2 = 1 #TRUE
        return root
        
    leftLCA = findLCAUtil(root.left,n1,n2,v1,v2)
    rightLCA = findLCAUtil(root.right,n1,n2,v1,v2)
    
    #if one is in left subtree
    #and other is in right subtree
    #return the ROOT
    if leftLCA and rightLCA :
        return root
    
    if leftLCA is not None:
        return leftLCA
    else:
        return rightLCA

def find(root,key):
    #if ROOT is NULL, return FALSE
    if root is None:
        return 0
    #Recursively Check the LEFT and RIGHT TREE
    if ((root.data == key) or find(root.left,key) or find(root.right,key)):
        return 1
    #if not FOUND return FALSE
    return 0
    
        
def findLCA(root,n1,n2):
    if root is None:
        return None
    v1 = 0 #FALSE
    v2 = 0 #FALSE
    
    lca = findLCAUtil(root,n1,n2,v1,v2)
    
    if ((v1 == 1 and v2 == 1) or (v1 == 1 and find(lca,n2)) or (v1 == 1 and find(lca,n2))):
        return lca
    
    return None



root1 = node(1)
root1.left = node(2)
root1.right = node(3)
root1.left.left = node(4)
root1.left.right = node(5)

node = findLCA(root1,4,5)

print "LCA of 4 and 5 is", node
