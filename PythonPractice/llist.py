
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        print "*****BEGIN*****"
        curr = self.head
        while curr is not None:
            print curr.data
            curr = curr.next
        print "******END******\n"
    
    def insertFront(self,data):
        curr = self.head
        
        if curr is None:
            temp = Node(data)
            self.head = temp
        else:
            temp = Node(data)
            temp.next = self.head
            self.head = temp
        self.printList()
        
    def insertAfter(self,pNode,data):
        if pNode is not None:
            temp = Node(data)
            pNode.next = temp
        self.printList()
    
    def insertTail(self,data):
        curr = self.head
        while curr.next is not None:
            curr = curr.next
        
        curr.next = Node(data)
        self.printList()
                
if __name__=='__main__':
    llist = LinkedList()
    second = Node(2)
    third = Node(3)
    fourth = Node(4)
    
    llist.head = Node(1)
    llist.head.next = second
    second.next = third
    third.next = fourth
    
    #List Traversal
    llist.printList()
    
    llist.insertFront(0)
    llist.insertAfter(fourth,5)
    llist.insertTail(6)
    
    
    
