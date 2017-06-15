# Stack CRLS 10.1
# 
# Pyseudocode 

def stack_empty(S):
    return S.top==0

def push(S,x):
    S.top += 1
    S[S.top] = x

def pop(S):
    if stack_empty(S):
        raise ValueError('empty')
    else:
        S.top -= 1
        return S[S.top + 1]

# Helper f
def make_stack():
    class Stack(list):
        def __str__(self):
           return str(self[1:self.top+1])
    S=Stack()
    S.top=0
    S.extend([None]*10)
    return S


G=make_stack()
for x in range(6):
    push(G,x)

print(G)

for x in range(6):
    print(pop(G),end=" ")

