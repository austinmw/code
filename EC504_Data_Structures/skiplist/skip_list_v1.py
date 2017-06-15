# Skip List
#

# when inserting
#   - maintain next, prev as lists
#   - add levels randomly
#                
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


def skiplist_search(L,k):
	y=L.head
	if not y:
		return None
	level=len(y.next)-1

	# find level

	while True:
		if not y.next[level]:
			if level == 0:
				return None
			level=level-1
			continue

		if y.next[level].key == k:  # found it
		    return y.next[level]
		elif y.next[level].key > k: # too far, go back
		    if level ==0:
		    	return None
		    level = level-1
		else:
			y=y.next[level]





def skiplist_insert(L,x):
	if not L.head: # handle empty
		L.head = x
		return

	y=L.head
	if x.key<y.key: # handle beginning
	  x.next=y
	  L.head=x
	  y.prev=x
	  return

	while y.next and (y.next.key < x.key):
		y=y.next

	x.next=y.next
	x.prev=y
	y.next=x

	if x.next:       # handle adding at the end
	  x.next.prev=x


def list_delete(L,x):
    if x.prev:
        x.prev.next=x.next
    else:
        L.head=x.next
    if x.next:
        x.next.prev=x.prev



class NodeUD():
    def __init__(self,Key=None,Prev=None,Next=None):
        self.prev=Prev
        self.next=Next
        self.up=None
        self.down=None
        self.key=Key
    def __str__(self):
        return str(self.key)


# Skip list node
# use lists to store ladder of levels.

class NodeSL():
    def __init__(self,Key=None):
        self.prev=[]
        self.next=[]
        self.key=Key
    def __str__(self):
        return str(self.key)


class Node_original():
    def __init__(self,Key=None,Prev=None,Next=None):
        self.prev=Prev
        self.next=Next
        self.key=Key
    def __str__(self):
        return str(self.key)















L=LinkedList()

w,x,y,z = NodeSL(5),NodeSL(7),NodeSL(8),NodeSL(9)

L.head=w
w.next[0]=x
x.next[0]=y
y.next[0]=z
z.next[0]=None
w.next.append(y)

skiplist_insert(L,NodeSL(8))
skiplist_insert(L,NodeSL(6))
skiplist_insert(L,NodeSL(7))
skiplist_insert(L,NodeSL(9))
print(L)


# g=list_search(L,5)
# list_delete(L,g)
# print(L)
# while g:
#     print(g)
#     g=g.prev

