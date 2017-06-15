# Queue. CRLS 10.1
#
# This is a simplified implementation of Stack using python list
#
# provides push(S,x) pop(S) and stack_empty(S
#

from collections import deque # deque is a Double Ended QUEue

class Queue(deque):
    pass

def enqueue(Q,x):
   Q.append(x)

def dequeue(Q):
    return Q.popleft()

def queue_empty(Q):
    return len(S)==0


Q=Queue()

for x in range(6):
    enqueue(Q,x)

print(Q)

for x in range(6):
    print(dequeue(Q),end=" ")

enqueue(Q,'s')
print(Q)
for x in range(12):
    enqueue(Q,x)
    print(dequeue(Q))
    print(Q)

