# Trees
import random


class Tree():
	def __init__(self,parent=None,left=None,right=None,key=None):
		self.parent=parent
		self.left=left
		self.right=right
		self.key=key

	def insert(self,z):
		
		if self.key==None:   # tree is empty
			self=z
			return 

		x=self
		while x:     # x != NIL
			y=x
			if z.key < x.key:
				x=x.left
			else:
				x=x.right
		z.parent=y
		if z.key < y.key:
			y.left=z
		else:
			y.right=z

def inorderwalk(x):
	if x:
		inorderwalk(x.left)
		print(x.key)
		inorderwalk(x.right)

def sorted(x):
	if x:
		return sorted(x.left) + [x.key] + sorted(x.right)
	else:
		return []

def topdownwalk(x,indent=0):
	if x:
		print(' '*indent +'key:',x.key)
		if x.left:
			print(' '*indent+'left')
			topdownwalk(x.left,indent+2)
		if x.right:
			print(' '*indent+'right')
			topdownwalk(x.right,indent+2)




new_tree=Tree()

L=random.sample(range(1000),10)

random.shuffle(L)

for item in L:
	n=Tree(key=item)
	#print(n)
	new_tree.insert(n)



L=sorted(new_tree)
print(L)

topdownwalk(new_tree)