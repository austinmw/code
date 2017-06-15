# Stack. CRLS 10.1
#
# This is a simplified implementation of Stack using python list
#
# provides push(S,x) pop(S) and stack_empty(S
#
class Stack(list):
    pass

def push(S,x):
   S.append(x)

def pop(S):
    return S.pop()

def stack_empty(S):
    return len(S)==0


S=Stack()

for x in [4,5,'ab',4.5]:
  push(S,x)

while not stack_empty(S):
    print(pop(S))

