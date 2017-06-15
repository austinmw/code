from pylab import *

T={}

for line in open('treestats.txt'):
    depth,count = (int(x) for x in line.split())
    T[depth]=count
G=array([0]*(max(T)+1))
for depth in T:
    G[depth]=T[depth]

print('Tree Depth Histogram')
print('Total nodes:',sum(G))
print('Actual: ',G)

treesize=sum(G)
GB = array([0]*(max(T)+1))
ii=0
while sum(GB) < treesize:
    GB[ii] = 2**ii
    ii += 1

GB[ii-1] -= sum(GB)-treesize

print('Perfect:',GB)

def meandep(A):
   X=A * (1+array(range(len(A))))
   return sum(X) / sum(A)



print('Average depth: {:.3f}'.format(meandep(G)))
print('Best possible depth: {:.3f}'.format(meandep(GB)))
print('Expansion factor: {:.3f}'.format(meandep(G)/meandep(GB)))

bar(array(range(len(G)))+0.6,G,color='blue')
bar(array(range(len(G)))+0.6,GB,color='red',width=0.4)
legend(['Actual','Ideal'])
title('Tree Depth Histogram')
show()
