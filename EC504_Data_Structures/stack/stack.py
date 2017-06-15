# Stack

class Stack():
    Size=10
    def __init__(self):
        self.top=0
        self.S=[0]*Stack.Size

    def push(self,x):
        self.S[self.top]=x
        self.top += 1

    def pop(self):
        if self.is_empty():
            raise ValueError('empty')
        else:
            self.top -= 1
            return self.S[self.top]
    
    def is_empty(self):
        return self.top == 0


    def __str__(self):
        return str(self.S[:self.top])

S=Stack()
for x in range(8):
  S.push(x)
for x in range(8):
    print(S.pop(),S.is_empty())

print(S)