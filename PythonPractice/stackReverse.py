class stack:
    def __init__(self,data):
        self.data = data
        self.next = None
        self.head = None
        return
    
    def push(self,data):
        temp = stack(data)
        temp.next = self.head
        self.head = temp
        return
    
    def pop(self):
        if self.head is None:
            print "Empty Stack"
            exit(1)
        temp = self.head
        self.head = temp.next
        return temp.data
    
    #inserts an element
    # at the bottom of a stack
    def insBottom(self,data):
        #if Stack is Empty
        #Push the Element to Bottom
        if self.head is None:
            self.push(data)
        else:
            #Pop the Elements and  
            #Put this at the Bottom
            item = self.pop()
            self.insBottom(data)
            self.push(item)
        return
    
    #Reverse the Stack Recursively
    def reversestack(self):
        if self.head is not None:
            item = self.pop()
            self.reversestack()
            self.insBottom(item)
            
    #Print the stack
    def printstack(self):
        temp = self.head
        while temp is not None:
            print "Data: ",temp.data
            temp = temp.next
        print
 
s = stack(0)
s.push(4)
s.push(3)
s.push(2)
s.push(1)

print("Original Stack ")
s.printstack()
 
s.reversestack()
 
print("Reversed Stack ")
s.printstack ()
