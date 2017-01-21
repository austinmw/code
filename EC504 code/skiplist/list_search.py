

def list_search(L,k):
    x=L.head
    while x and x.key != k:
        x=x.next
    return x


class LinkedList():
    def __init__(self):
     self.head=None
    def __str__(self):
        x="Head -> "
        n=self.head
        while n:
            x += str(n.key) + " -> "
            n=n.next
        return x[:-4]

def list_insert(L,x):
    x.next=L.head
    if L.head:
        L.head.prev=x
    L.head=x
    x.prev=None

def list_delete(L,x):
    if x.prev:
        x.prev.next=x.next
    else:
        L.head=x.next
    if x.next:
        x.next.prev=x.prev



class Node():
    def __init__(self,Key=None,Prev=None,Next=None):
        self.prev=Prev
        self.next=Next
        self.key=Key
    def __str__(self):
        return str(self.key)


L=LinkedList()

list_insert(L,Node(5))
list_insert(L,Node(6))
list_insert(L,Node(8))
print(L)
n=Node()


g=list_search(L,5)
list_delete(L,g)
print(L)
while g:
    print(g)
    g=g.prev

