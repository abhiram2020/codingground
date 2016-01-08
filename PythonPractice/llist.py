
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
        
        if curr is None:
            self.head = Node(data)
            return
        
        while curr.next is not None:
            curr = curr.next
        
        curr.next = Node(data)
        self.printList()
        
    def delNodeWithKey(self,data):
        if self.head is None:
            return
        if self.head.data == data:
            temp = self.head.next
            del self.head
            self.head = temp
        else:
            curr = self.head
            while curr.next is not None:
                if curr.next.data == data:
                    nextNext = curr.next.next
                    temp = curr.next
                    curr.next = nextNext
                    del temp
                    break
                else:    
                    curr = curr.next
        self.printList()
        
    def delNodeGivenPos(self,pos):
        if self.head is None:
            return
        count = 0
        cur = self.head
        if pos == 0:
            self.head = cur.next
            del cur
        else:
            while (count < (pos-1)):
                cur = cur.next
                count = count+1
            
            if cur is None or cur.next is None:
                return
            
            nextNext = cur.next.next
            del cur.next
            cur.next = nextNext
            
        self.printList()
        
                
if __name__=='__main__':
    llist  = LinkedList()
    second = Node(2)
    third  = Node(3)
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
    
    #llist.delNodeWithKey(0)
    #llist.delNodeWithKey(6)
    
    llist.delNodeGivenPos(0)
    llist.delNodeGivenPos(5)
    
    
    
