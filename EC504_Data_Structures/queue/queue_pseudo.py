# Stack CRLS 10.1
# 
# Pyseudocode 

def enqueue(Q,x):
    Q[Q.tail] = x
    if Q.tail == Q.length:
        Q.tail = 1
    else:
        Q.tail += 1

def dequeue(Q):
    x=Q[Q.head]
    if Q.head == Q.length:
        Q.head = 1
    else:
        Q.head += 1
    return x


# Helper f
def make_queue(length=10):
    class Queue(list):
        def __str__(self):
            if Q.head < Q.tail:
              return "Queue:"+str(Q[Q.head:Q.tail])
            else:
              return "Queue"+str(Q[Q.head:]+Q[1:Q.tail])

    Q=Queue()
    Q.tail=1
    Q.head=1
    Q.length=9
    Q.extend([None]*length)
    return Q


Q=make_queue(10)
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
