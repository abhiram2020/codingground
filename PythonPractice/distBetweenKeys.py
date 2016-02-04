import sys
class node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

def finddistUtil(root,n1,n2,d1,d2,dist,lvl):
    if root is None:
        return -1
    
    if root.data == n1:
        d1 = lvl
        return root
    
    if root.data == n2:
        d2 = lvl
        return root
        
    leftLCA = finddistUtil(root.left,n1,n2,d1,d2,dist,lvl+1)
    rightLCA = finddistUtil(root.right,n1,n2,d1,d2,dist,lvl+1)
    
    #if one is in left subtree
    #and other is in right subtree
    #return the ROOT
    if leftLCA and rightLCA :
        dist = d1 + d2 - (2 * lvl)
        return dist
    
    if leftLCA is not None:
        return leftLCA
    else:
        return rightLCA

def find(root,key,lvl):
    #if ROOT is NULL, return FALSE
    if root is None:
        return -1
    
    if root.data == key:
        return lvl
        
    left = find(root.left,key,lvl+1)
    
    if left != -1:
        return lvl
    else:
        return find(root.right,key,lvl+1)
    
        
def finddist(root,n1,n2):
    if root is None:
        return None
    d1 = -1 #FALSE
    d2 = -1 #FALSE
    dist = 0
    lca = finddistUtil(root,n1,n2,d1,d2,dist,1)
    
    if d1 != -1 and d2 != -1:
        return dist
    
    #NODE N1 is ancestor of N2, find N2
    #in the SUBTREE headed by N1
    if d1 != -1:
        dist = find(lca,n2,0)
        return dist
        
    #NODE N2 is ancestor of N1, find N1
    #in the SUBTREE headed by N2
    if d2 != -1:
        dist = find(lca,n1,0)
        return dist
    
    return -1



root1 = node(1)
root1.left = node(2)
root1.right = node(3)
root1.left.left = node(4)
root1.left.right = node(5)

dist = finddist(root1,4,5)

print "Dist Bewtween 4 and 5 is", dist
