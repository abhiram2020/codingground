class twostacks:
    
    def __init__(self,capacity):
        self.arr = [0]*capacity
        self.t1 = -1
        self.t2 = capacity
        self.size = capacity
        return
    
    def push1(self,data):
        if(self.t1 < self.t2-1 ):
            self.t1 = self.t1 + 1
            self.arr[self.t1] = data
            print "T1:",self.t1, "Data",data
            return
        else:
            print "STACK OVERFLOW"
            exit(1)
    
    def push2(self,data):
        if(self.t1 < self.t2 -1 ):
            self.t2 = self.t2 - 1
            self.arr[self.t2] = data
            print "T2:",self.t2, "Data",data
            return
        else:
            print "STACK OVERFLOW"
            exit(1)
    
    def pop1(self):
        if (self.t1 >= 0):
            data = self.arr[self.t1]
            print "T1:",self.t1, "Data",data
            self.t1 = self.t1 - 1
            return data
        else:
            print "Stack Underflow "
            exit(1)
            
    def pop2(self):
        if (self.t2 < self.size):
            data = self.arr[self.t2]
            print "T2:",self.t2, "Data",data
            self.t2 = self.t2 + 1
            return data
        else:
            print "Stack Underflow "
            exit(1)
            
ts = twostacks(5)
ts.push1(5)
ts.push2(10)
ts.push2(15)
ts.push1(11)
ts.push2(7)
print "******"
print "Popped element from stack1 is ", ts.pop1()
ts.push2(40)
print "Popped element from stack2 is ", ts.pop2()
